#include <iostream>
#include "main.hpp"

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
/*
todo:
	- authenticate user
	- open user menu
*/
void login(){
	user_menu();
	menu();
}
//todo: add a new user
void reg(){
	menu();
}
//todo: run client
void listener(){
	menu();
}

void menu() {
	int opt = -1;
	//bool valid = false;

	cout << "Select an Option\n";
	cout << "[0] - Exit \n";
	cout << "[1] - User Login\n";
	cout << "[2] - User Registration\n";
	cout << "[3] - Run Listener\n";
	cout << "\n";

	while(true){
		cout << "Option:";
		cin >> opt;

		/* todo:
					- check for characters
					- fix flow bugs
		*/
		switch(opt){
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
			}
		}
	}
}

int main() {
	title();
	menu();

	return 0;
}
