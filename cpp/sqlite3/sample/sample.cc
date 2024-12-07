#include <sqlite3.h>

#include <iostream>
#include <string>
#include <vector>

class SQLite {
 public:
  SQLite(const std::string& path) : db_(nullptr), err_msg_(nullptr) {
    if (sqlite3_open(path.c_str(), &db_) != SQLITE_OK) {
      std::cerr << "Cannot open sqlite db: " << path << ", "
                << sqlite3_errmsg(db_) << std::endl;
      sqlite3_close(db_);
      db_ = nullptr;
    }
  }

  ~SQLite() {
    if (db_) {
      sqlite3_close(db_);
    }
  }

  int exec(const std::string& sql) {
    char* err_msg = nullptr;
    return sqlite3_exec(db_, sql.c_str(), 0, 0, &err_msg);
  }

  void add_log(const std::string& log_message) {
    const std::string sql = "INSERT INTO log(log) VALUES(?)";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
      std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db_)
                << std::endl;
      return;
    }

    sqlite3_bind_text(stmt, 1, log_message.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt) != SQLITE_DONE) {
      std::cerr << "Execution failed: " << sqlite3_errmsg(db_) << std::endl;
      return;
    }
    sqlite3_finalize(stmt);
  }

  void add_logs(const std::vector<std::string>& messages) {
    const std::string sql = "INSERT INTO log(log) VALUES(?)";
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db_, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
      std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db_)
                << std::endl;
      return;
    }

    for (std::string msg : messages) {
      sqlite3_bind_text(stmt, 1, msg.c_str(), -1, SQLITE_STATIC);
      if (sqlite3_step(stmt) != SQLITE_DONE) {
        std::cerr << "Execution failed: " << sqlite3_errmsg(db_) << std::endl;
      }
      sqlite3_reset(stmt);
    }
    if (sqlite3_exec(db_, "COMMIT;", 0, 0, NULL) != SQLITE_OK) {
      std::cerr << "Execution failed: " << sqlite3_errmsg(db_) << std::endl;
      return;
    }

    sqlite3_finalize(stmt);
  }

 private:
  sqlite3* db_;
  char* err_msg_;
};

int main(void) {
  const std::string db_path = "test.db";

  SQLite db(db_path);
  std::string sql =
      "CREATE TABLE IF NOT EXISTS log("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "log TEXT NOT NULL,"
      "t DATETIME DEFAULT CURRENT_TIMESTAMP"
      ")";
  db.exec(sql);

  // for (int i = 0; i < 100; ++i) {
  //   std::string message = "message - " + std::to_string(i);
  //   db.add_log(message);
  // }

  std::vector<std::string> message;
  for (int i = 0; i < 1000; ++i) {
    message.push_back("message - " + std::to_string(i));
  }

  db.add_logs(message);

  return 0;
}
