#include "sqlite.h"

#include <iostream>

namespace sqlite {
SQLite::SQLite(const std::string& path) : db_(nullptr) {
  if (sqlite3_open(path.c_str(), &db_) != SQLITE_OK) {
    std::cerr << "Cannot open sqlite db: " << path << ", "
              << sqlite3_errmsg(db_) << std::endl;
    sqlite3_close(db_);
    db_ = nullptr;
  }
}

SQLite::~SQLite() {
  if (db_) {
    sqlite3_close(db_);
  }
}

int SQLite::exec(const std::string& sql) {
  return sqlite3_exec(db_, sql.c_str(), 0, 0, &err_msg_);
}

SQLiteStatement::SQLiteStatement(sqlite3* db, std::string sql)
    : stmt_(nullptr) {
  if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt_, nullptr) != SQLITE_OK) {
    std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db)
              << std::endl;
    return;
  }
}

SQLiteStatement::~SQLiteStatement() {
  if (stmt_) {
    sqlite3_finalize(stmt_);
  }
}
}  // namespace sqlite
