#include <iostream>
#include <vector>

#include "sqlite.h"

int main(void) {
  using namespace sqlite;

  const std::string db_path = "test.db";

  SQLite db(db_path);
  std::string sql =
      "CREATE TABLE IF NOT EXISTS log("
      "id INTEGER PRIMARY KEY AUTOINCREMENT,"
      "log TEXT NOT NULL,"
      "t DATETIME DEFAULT CURRENT_TIMESTAMP"
      ")";
  db.exec(sql);

  SQLiteStatement stmt(db.db(), "INSERT INTO log(log) VALUES(?)");
  std::vector<std::string> message;
  for (int i = 0; i < 1000; ++i) {
    std::string message = "message - " + std::to_string(i);
    sqlite3_bind_text(stmt.stmt(), 1, message.c_str(), -1, SQLITE_STATIC);
    if (sqlite3_step(stmt.stmt()) != SQLITE_DONE) {
      std::cerr << "Execution failed: " << sqlite3_errmsg(db.db()) << std::endl;
    }
    sqlite3_reset(stmt.stmt());
  }
  return 0;
}
