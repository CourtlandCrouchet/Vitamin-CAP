#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <string>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    //prints table info
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
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
    string temp = "INSERT INTO " +table+ " VALUES ("+query+");";
    cout<<temp<<endl;
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
//still working on this
int user_auth(string username, string password)
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;
    bool login = false;
    
    /* Open database */
    rc = sqlite3_open("vcap.db", &db);
    
    /* Create SQL statement */
    string temp = "SELECT username, password from users where username = '"+username+"' and password = '"+password+"'";;
    const char *line1 = temp.c_str();
    sql = line1;
    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql,callback,0, &zErrMsg);
    cout<<rc<<endl;
    if(rc == 0)
    {
        fprintf(stdout,"Login Successful.\n");
        login = true;
    }
    else
    {
        fprintf(stdout,"Incorrect Username or Password.\n");
        login = false;
    }
    sqlite3_close(db);
    return 0;
}

int main()
{
    //user_auth("nurse","password1");
    //string sql;
    //string query;
    
    //insert for users
    /*
     cout<<"Enter ID:";
     cin>>query;
     sql.append(query);
     sql.append(",");
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
     cout<<"Enter ID:";
     cin>>query;
     sql.append(query);
     sql.append(",");
     cout<<"Enter Name:";
     sql.append("'");
     cin>>query;
     sql.append(query);
     sql.append("'");
     insert("diseases",sql);
     sql="";
     */
    
    //insert for diagnoses
    /*
     cout<<"Enter ID: ";
     cin>>query;
     sql.append(query);
     sql.append(",");
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
}









