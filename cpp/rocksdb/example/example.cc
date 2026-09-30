#include <rocksdb/db.h>

#include <iostream>
#include <string>

int main(void) {
  std::unique_ptr<rocksdb::DB> db;
  rocksdb::Options options;

  // Create the database directory if it doesn't already exist
  options.create_if_missing = true;
  std::string db_path = "/tmp/testdb";

  rocksdb::Status status = rocksdb::DB::Open(options, db_path, &db);
  if (!status.ok()) {
    std::cerr << "Failed to open RocksDB: " << status.ToString() << std::endl;
    return 1;
  }

  // PUT
  rocksdb::WriteOptions write_options;
  status = db->Put(write_options, "user_101", "Alice");
  if (status.ok()) {
    db->Put(write_options, "user_102", "Bob");
    db->Put(write_options, "user_103", "Charlie");
    std::cout << "Successfully wrote key-value pairs.\n";
  }

  // GET
  rocksdb::ReadOptions read_options;
  std::string value;
  status = db->Get(read_options, "user_101", &value);

  if (status.ok()) {
    std::cout << "Retrieved key 'user_101': " << value << std::endl;
  } else if (status.IsNotFound()) {
    std::cout << "Key 'user_101' not found.\n";
  }

  // ITERATE
  std::cout << "\n--- Iterating through DB ---" << std::endl;
  rocksdb::Iterator* it = db->NewIterator(read_options);
  for (it->SeekToFirst(); it->Valid(); it->Next()) {
    std::cout << it->key().ToString() << " -> " << it->value().ToString()
              << std::endl;
  }
  delete it;  // Always clean up iterators

  // DELETE
  status = db->Delete(write_options, "user_102");
  if (status.ok()) {
    std::cout << "\nDeleted key 'user_102'.\n";
  }
  return 0;
}
