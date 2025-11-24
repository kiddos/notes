#include <lmdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_PATH "/tmp/lmdb_test"
#define TEMP_DB_PATH "/dev/shm/my_temp_lmdb" // Use a RAM-backed location on Linux

int main(void) {
  MDB_env *env = NULL;
  MDB_dbi dbi;

  int rc = mdb_env_create(&env);
  if (rc != 0) {
    goto fail;
  }

  rc = mdb_env_set_mapsize(env, 10 * 1024 * 1024); 
  if (rc != 0) {
    goto fail;
  }

  printf("Opening LMDB environment at: %s\n", DB_PATH);
  // rc = mdb_env_open(env, DB_PATH, 0, 0664); 
  rc = mdb_env_open(env, TEMP_DB_PATH, MDB_NOSYNC | MDB_NOMETASYNC | MDB_NOSUBDIR, 0664);
  if (rc != 0) {
    goto fail;
  }

  MDB_txn *txn_w = NULL;
  rc = mdb_txn_begin(env, NULL, 0, &txn_w);
  if (rc != 0) {
    goto fail;
  }

  rc = mdb_dbi_open(txn_w, NULL, MDB_CREATE, &dbi); 
  if (rc != 0) {
    goto fail;
  }

  MDB_val key, data;
  char* key_str = "user_id_42";
  char* data_str = "Name: Alice, Age: 30";
  key.mv_size = strlen(key_str);
  key.mv_data = key_str;
  data.mv_size = strlen(data_str);
  data.mv_data = data_str;

  rc = mdb_put(txn_w, dbi, &key, &data, 0);
  if (rc != 0) {
    goto fail;
  }

  rc = mdb_txn_commit(txn_w);
  if (rc != 0) {
    goto fail;
  }

  MDB_txn *txn_r = NULL;
  rc = mdb_txn_begin(env, NULL, MDB_RDONLY, &txn_r);
  if (rc != 0) {
    goto fail;
  }

  MDB_val read_data;
  rc = mdb_get(txn_r, dbi, &key, &read_data);
  if (rc == MDB_NOTFOUND) {
    printf("Key not found.\n");
    mdb_txn_abort(txn_r);
  } else if (rc != 0) {
    goto fail;
  } else {
    printf("Successfully retrieved Key: '%s'\n", (char *)key.mv_data);
    printf("Retrieved Value: '%.*s'\n", (int)read_data.mv_size, (char *)read_data.mv_data);
  }

  mdb_dbi_close(env, dbi);
  mdb_env_close(env);
  
  printf("\nLMDB operations complete.\n");
  return EXIT_SUCCESS;

fail:
  fprintf(stderr, "LMDB Error: %s\n", mdb_strerror(rc));
  if (env) {
    if (txn_w) mdb_txn_abort(txn_w); 
    if (txn_r) mdb_txn_abort(txn_r);
    mdb_env_close(env);
  }
  return EXIT_FAILURE;
}
