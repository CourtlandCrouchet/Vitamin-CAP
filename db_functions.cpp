#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include <iostream>
#include <string>
using namespace std;


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   int i;
   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int add_user(int id, string username, string password) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char *sql;

   /* Open database */
   rc = sqlite3_open("vcap.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   /* Create SQL statement */
   string temp = "INSERT INTO USERS VALUES ("+to_string(id)+",'"+username+"','"+password+"');";
   const char *line1 = temp.c_str();
   sql = line1;         
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Added User Successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

int add_disease(int id, string name) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char *sql;

   /* Open database */
   rc = sqlite3_open("vcap.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   /* Create SQL statement */
   string temp = "INSERT INTO DISEASES VALUES ("+to_string(id)+",'"+name+"');";
   const char *line1 = temp.c_str();
   sql = line1;         
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Added Disease Successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

int add_diagnose(int id, string date, int user, int disease) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   const char *sql;

   /* Open database */
   rc = sqlite3_open("vcap.db", &db);
   
   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }
   /* Create SQL statement */
   string temp = "INSERT INTO DIAGNOSES VALUES ("+to_string(id)+",'"+date+"',"+to_string(user)+","+to_string(disease)+");";
   const char *line1 = temp.c_str();
   sql = line1;         
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
   
   if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Added Diagnoses Successfully\n");
   }
   sqlite3_close(db);
   return 0;
}

int main()
{

int id;
string date;
int user;
int disease;
cout << "enter id:";
cin>>id;
cout << "enter date:";
cin>>date;
cout << "enter user:";
cin>>user;
cout << "enter disease:";
cin>>disease;
add_diagnose(id,date,user,disease);

}
