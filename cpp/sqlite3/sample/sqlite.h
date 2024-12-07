#include <sqlite3.h>

#include <string>

namespace sqlite {

class SQLite {
 public:
  SQLite(const std::string& path);
  ~SQLite();

  int exec(const std::string& sql);

  inline sqlite3* db() const { return db_; }

 private:
  sqlite3* db_;
  char* err_msg_;
};

class SQLiteStatement {
 public:
  SQLiteStatement(sqlite3* db, std::string sql);
  ~SQLiteStatement();

  inline sqlite3_stmt* stmt() const { return stmt_; }

 private:
  sqlite3_stmt* stmt_;
};
}  // namespace sqlite
