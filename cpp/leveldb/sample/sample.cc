#include <iostream>
#include <leveldb/db.h>

int main(void) {
  leveldb::DB *db;
  leveldb::Options options;
  options.create_if_missing = true;

  leveldb::Status status = leveldb::DB::Open(options, "test.db", &db);
  if (!status.ok()) {
    std::cerr << "Unable to open/create database: " << status.ToString()
              << std::endl;
    return -1;
  }

  for (int i = 0; i < 100; ++i) {
    db->Put(leveldb::WriteOptions(), "key" + std::to_string(i), "value" + std::to_string(i));
  }

  std::string value;
  db->Get(leveldb::ReadOptions(), "key1", &value);
  std::cout << "Read value: " << value << std::endl;

  delete db;
  return 0;
}
