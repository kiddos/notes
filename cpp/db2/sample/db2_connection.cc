#include "db2_connection.h"

#include <iostream>

namespace db2 {

bool check_ret_code(SQLRETURN code, SQLHANDLE handle, SQLSMALLINT handle_type,
                    const char* msg) {
  if (code != SQL_SUCCESS && code != SQL_SUCCESS_WITH_INFO) {
    SQLCHAR sql_state[6], error_msg[1024];
    SQLINTEGER native_error;
    SQLSMALLINT length;

    SQLGetDiagRec(handle_type, handle, 1, sql_state, &native_error, error_msg,
                  sizeof(error_msg), &length);

    std::cerr << "ERROR: " << msg << "\n"
              << "SQL State: " << sql_state << "\n"
              << "Message: " << error_msg << "\n";
    return false;
  }
  return true;
}

DB2Connection::DB2Connection() { setup(); }

DB2Connection::~DB2Connection() {
  SQLDisconnect(dbc_);
  SQLFreeHandle(SQL_HANDLE_DBC, dbc_);
  SQLFreeHandle(SQL_HANDLE_ENV, env_);
}

bool DB2Connection::setup() {
  auto code = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env_);
  if (!check_ret_code(code, env_, SQL_HANDLE_ENV,
                      "Allocating Environemnt handle")) {
    return false;
  }

  code = SQLSetEnvAttr(env_, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
  if (!check_ret_code(code, env_, SQL_HANDLE_ENV,
                      "Setting Environment Attributes")) {
    return false;
  }

  code = SQLAllocHandle(SQL_HANDLE_DBC, env_, &dbc_);
  if (!check_ret_code(code, dbc_, SQL_HANDLE_DBC,
                      "Allocating Connection Handle")) {
    return false;
  }
  return true;
}

bool DB2Connection::Connect(std::string connection_str) {
  auto code = SQLDriverConnect(dbc_, NULL, (SQLCHAR*)connection_str.c_str(),
                               SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);
  if (!check_ret_code(code, dbc_, SQL_HANDLE_DBC, "Connecting to Database")) {
    return false;
  }
  std::cout << "Connected to Db2 database successfully!" << std::endl;
  return true;
}

std::unique_ptr<DB2Statement> DB2Connection::Execute(std::string sql) {
  SQLHSTMT stmt;
  auto code = SQLAllocHandle(SQL_HANDLE_STMT, dbc_, &stmt);
  if (!check_ret_code(code, stmt, SQL_HANDLE_STMT,
                      "Allocating Statement Handle")) {
    return nullptr;
  }

  code = SQLExecDirect(stmt, (SQLCHAR*)sql.c_str(), SQL_NTS);
  if (!check_ret_code(code, stmt, SQL_HANDLE_STMT, "Executing Query")) {
    return nullptr;
  }
  return std::make_unique<DB2Statement>(stmt);
}

DB2Statement::DB2Statement(SQLHSTMT stmt) : stmt_(stmt) {}

DB2Statement::~DB2Statement() { SQLFreeHandle(SQL_HANDLE_STMT, stmt_); }

bool DB2Statement::next() { return SQLFetch(stmt_) == SQL_SUCCESS; }

}  // namespace db2
