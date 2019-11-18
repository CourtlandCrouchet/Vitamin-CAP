/*
Author(s): Raphaela, JJ
Updated: 11/16/19
Description: Main program of the application
*/
#include <iostream>
#include <string>
#include "main.hpp"
#include "client.hpp"
#include "cap_parse.hpp"
#include "db_functions.hpp"

using namespace std;

void title() {
	//http://patorjk.com/software/taag/#p=display&f=Ogre&t=Vitamin%20CAP
	cout << "        _ _                  _           ___      " 		<< endl;
	cout << " /\\   /(_) |_ __ _ _ __ ___ (_)_ __     / _\\_\\__ _ _ __  " 		<< endl;
	cout << " \\ \\ / / | __/ _` | '_ ` _ \\| | '_ \\   / /  / _` | '_ \\ " 	<< endl;
	cout << "  \\ V /| | || (_| | | | | | | | | | | / /__| (_| | |_) |" 		<< endl;
	cout << "   \\_/ |_|\\__\\__,_|_| |_| |_|_|_| |_| \\____/\\__,_| .__/ " 	<< endl;
	cout << "                                                 |_|   "		<< endl;
}

void login(){
	string user, passwd;
	int uid = 0;
	cout << "\nUser: ";
	cin >> user;
	cout << "\nPassword: ";
	cin >> passwd;
	uid = user_auth(user, passwd);
	//cout << uid << endl;
	if (uid)
	//if (uid && uid < 100)
		user_menu();
	else
		cout << "User not found." << endl;
	menu();
}

void reg(){
	string sql, query;
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
	menu();
}

void listener(){
	int port = 49999;
	string ip_addr = "127.0.0.1";
	//Function takes an IP address and port no
  ConnectToUser(ip_addr, port);
	cap_parse();
	menu();
}

void menu() {
	int opt = -1;
	//bool valid = false;

//	while(!valid){
		cout << "\n";
		cout << "Select an Option\n";
		cout << "[0] - Exit \n";
		cout << "[1] - User Login\n";
		cout << "[2] - User Registration\n";
		cout << "[3] - Run Listener\n";
		cout << "\n";

		cout << "Option: ";
		cin >> opt;

		/* todo:
					- check for characters
					- fix flow bugs
		*/
		switch(opt){
			case -1: {
				//valid = true;
				break;
			}
			case 0:
				exit(0);

			case 1: {
				login();
				break;
			}

			case 2: {
				reg();
				break;
			}

			case 3: {
				listener();
				break;
			}

			default: {
				cout << "Invalid option, please try again." << endl;
				menu();
			}
		}
	//}
}

int main() {
	title();
	menu();

	return 0;
}
