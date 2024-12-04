#include <sqlcli1.h>

#include <string>
#include <memory>

namespace db2 {

class DB2Statement {
 public:
  DB2Statement(SQLHSTMT stmt);
  ~DB2Statement();

  bool next();
  inline SQLHSTMT handle() { return stmt_; }

 private:
  SQLHSTMT stmt_;
};

class DB2Connection {
 public:
  DB2Connection();
  ~DB2Connection();

  bool Connect(std::string connection_str);
  std::unique_ptr<DB2Statement> Execute(std::string sql);

 private:
  SQLHENV env_;
  SQLHDBC dbc_;

  bool setup();
};
  
}
