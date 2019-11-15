/*
 Author(s): Cameron Navero
 Updated: 11/14/2019
 Description: Function for calling and updating the database.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <string>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i=0; i+1<argc; i++)
    {
        printf("%s %s\n", argv[i], argv[i+1]);
    }
    return 0;
}

//insert function for all inserts
int insert(string table, string query)
{
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
    string temp = "INSERT INTO " +table+ " VALUES (null,"+query+");";
    const char *line1 = temp.c_str();
    sql = line1;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Added Successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

//User authortication
int user_auth(string username, string password)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    int loginID=0;
    
    /* Open database */
    rc = sqlite3_open("vcap.db", &db);
    /* Create SQL statement */
    string temp = "select userid from users where username = '"+username+"' and password = '"+password+"';";
    const char *line1 = temp.c_str();
    sql = line1;
    
    struct sqlite3_stmt *selectstmt;
    int result = sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL);
    if(result == SQLITE_OK)
    {
        if (sqlite3_step(selectstmt) == SQLITE_ROW)
        {
            loginID = sqlite3_column_int(selectstmt,0);
        }
    }
    sqlite3_finalize(selectstmt);
    sqlite3_close(db);
    return loginID;
}
//function for sql selects
int select(string query)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    const char* data = "Callback function called";
    
    /* Open database */
    rc = sqlite3_open("vcap.db", &db);
    
    if( rc ) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    } else {
        fprintf(stderr, "Opened database successfully\n");
    }
    
    /* Create SQL statement */
    //returns disease with count
    const char *temp = query.c_str();
    sql = temp;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);
    
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}

//   ** SELECT STATEMENTS TO CALL SELECT(). **
//Count diseases and orders them by DESC
//string sql = "SELECT name,count(name) from Diagnoses , Diseases WHERE diseases.diseaseID = diagnoses.DiseaseID GROUP BY name ORDER BY count(name) desc";
//Return username and the number of diagnoses inputed
//string sql = "SELECT username, count(diagnoses.userID) FROM users, diagnoses WHERE users.userID = diagnoses.userID GROUP BY diagnoses.userID";
//Returns the disease within the last 7 days with the count
//string sql = "SELECT name , count(diagnoses.diseaseID) FROM diseases, diagnoses WHERE diagnoseDate > (SELECT DATE('now','-7 day')) AND diagnoses.diseaseID=diseases.diseaseID GROUP BY diagnoses.diseaseID";
//select(sql);

// SELECT * FROM session WHERE stop_time > (SELECT DATETIME('now', '-7 day'))

// ***BELOW ARE HOW THE FUNCTIONS ARE CALLED***

//User auth function
/*
 int login = user_auth("nurse1","nurse20");
 cout<<login<<endl;
 if(login){
 cout<<"Login Successful\n";
 }
 else
 {
 cout<<"Incorrect Username or Password.\n";
 }
 login = user_auth("nurse1","nurse20");
 cout<<login<<endl;
 if(login){
 cout<<"Login Successful\n";
 }
 else
 {
 cout<<"Incorrect Username or Password.\n";
 }
 login = user_auth("nurse1","password1");
 cout<<login<<endl;
 if(login){
 cout<<"Login Successful\n";
 }
 else
 {
 cout<<"Incorrect Username or Password.\n";
 }
 */


//insert for user
/*
 string sql;
 string query;
 
 cout<<"Enter Name:";
 sql.append("'");
 cin>>query;
 sql.append(query);
 sql.append("'");
 sql.append(",");
 cout<<"Enter password:";
 cin>>query;
 sql.append("'");
 sql.append(query);
 sql.append("'");
 insert("users",sql);
 sql = "";
 */

//insert for disease
/*
 string sql;
 string query;
 
 cout<<"Enter Name:";
 sql.append("'");
 cin>>query;
 sql.append(query);
 sql.append("'");
 insert("diseases",sql);
 sql="";
 }
 */
//insert for diagnoses
/*
 string sql;
 string query;
 
 cout<<"Enter Date: ";
 sql.append("'");
 cin>>query;
 sql.append(query);
 sql.append("'");
 sql.append(",");
 cout<<"Enter Nurse ID: ";
 sql.append("'");
 cin>>query;
 sql.append(query);
 sql.append("'");
 sql.append(",");
 cout<<"Enter Disease ID: ";
 sql.append("'");
 cin>>query;
 sql.append(query);
 sql.append("'");
 insert("Diagnoses",sql);
 sql="";
 */

//select count of disease desc
//string sql = "SELECT name,count(name) from Diagnoses , Diseases WHERE diseases.diseaseID = diagnoses.DiseaseID GROUP BY name ORDER BY count(name) desc";






