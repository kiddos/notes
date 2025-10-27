#include <iostream>
#include <vector>
#include <sqlite3.h>

int main(void) {
  const std::string db_path = "test.db";
  sqlite3* db = nullptr;

  if (sqlite3_open(db_path.c_str(), &db) != SQLITE_OK) {
    std::cerr << "Cannot open sqlite db: " << db_path << ", "
              << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return 1;
  }


  std::string sql =
      "CREATE TABLE IF NOT EXISTS log("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "log TEXT NOT NULL,"
      "t DATETIME DEFAULT CURRENT_TIMESTAMP"
      ")";

  char* err_msg = nullptr;
  if (sqlite3_exec(db, sql.c_str(), 0, 0, &err_msg) != SQLITE_OK) {
    std::cerr << "Cannot create table: " << sqlite3_errmsg(db) << std::endl;
    sqlite3_close(db);
    return 1;
  }

  std::vector<std::string> message;
  for (int i = 0; i < 3; ++i) {
    sqlite3_stmt* stmt = nullptr;
    sql = "INSERT INTO log(log) VALUES(?)";
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
      std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
      break;
    }

    std::string message = "message - " + std::to_string(i);
    sqlite3_bind_text(stmt, 1, message.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
      std::cerr << "Execution failed: " << sqlite3_errmsg(db) << std::endl;
      break;
    }
    sqlite3_finalize(stmt);
  }

  sqlite3_close(db);
  return 0;
}
