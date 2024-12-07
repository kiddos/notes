#include <sqlcli1.h>

#include <iostream>
#include <string>
#include <vector>

#include "db2_connection.h"

struct Employee {
  int id;
  std::string first_name, last_name, email;

  Employee(int id, char* first_name, char* last_name, char* email)
      : id(id), first_name(first_name), last_name(last_name), email(email) {}
};

int main(void) {
  db2::DB2Connection conn;
  std::string connection_str =
      "DRIVER={IBM DB2 ODBC DRIVER};"
      "HOSTNAME=localhost;"
      "DATABASE=TESTDB;"
      "UID=db2inst1;"
      "PWD=a123456;";
  conn.Connect(connection_str);

  std::string query = "SELECT * FROM EMPLOYEES";
  auto stmt = conn.Execute(query);

  std::vector<Employee> users;
  while (stmt && stmt->next()) {
    SQLINTEGER id;
    SQLCHAR first_name[50], last_name[50], email[100];
    SQLGetData(stmt->handle(), 1, SQL_C_LONG, &id, 0, nullptr);
    SQLGetData(stmt->handle(), 2, SQL_C_CHAR, first_name, sizeof(first_name),
               nullptr);
    SQLGetData(stmt->handle(), 3, SQL_C_CHAR, last_name, sizeof(last_name),
               nullptr);
    SQLGetData(stmt->handle(), 4, SQL_C_CHAR, email, sizeof(email), nullptr);
    users.push_back(
        Employee((int)id, (char*)first_name, (char*)last_name, (char*)email));
  }
  for (Employee u : users) {
    std::cout << "id=" << u.id << ", " << u.first_name << " " << u.last_name
              << " (" << u.email << ")" << std::endl;
  }

  return 0;
}
