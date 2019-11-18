/*
Author(s): Raphaela
Updated: 10/20/19
Description: Main program of the application
*/
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <iostream>
#include <string>
using namespace std;

static int callback(void *NotUsed, int argc, char **argv, char **azColName);
int insert(string table, string query);
int user_auth(string username, string password);
