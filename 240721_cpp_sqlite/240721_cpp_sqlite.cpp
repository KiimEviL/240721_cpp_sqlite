#include <iostream>
#include <string>
#include "sqlite/sqlite3.h"
using namespace std;

int main() {
	char* err;
	sqlite3* db;
	sqlite3_stmt* s;
	sqlite3_open("DB.db", &db);

	string sql = "CREATE TABLE IF NOT EXISTS GRADES("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"NAME      TEXT NOT NULL, "
		"LNAME     TEXT NOT NULL, "
		"AGE       INT  NOT NULL, "
		"ADDRESS   CHAR(50), "
		"GRADE     CHAR(1) );";
	int rc = sqlite3_exec(db, "CREATE TABLE IF NOT EXISTS GRADES(ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME      TEXT NOT NULL, LNAME     TEXT NOT NULL, AGE       INT  NOT NULL, ADDRESS   CHAR(50), GRADE     CHAR(1) );", NULL, NULL, &err);
	if (rc != SQLITE_OK) {
		cerr << "Creating table error: " << err;
	}
	return 0;
}