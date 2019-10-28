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
void login(){}
//todo: add a new user
void reg(){}
//todo: run client
void listener(){}

int main() {
	title();

	int opt = -1;
	bool valid = false;

	cout << "Select an Option\n";
	cout << "[0] - Exit \n";
	cout << "[1] - User Login\n";
	cout << "[2] - User Registration\n";
	cout << "[3] - Send Message\n";
	cout << "\n";

	while(!valid){
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
				send();
				break;
			}
		}

		cout << "Option:";
		cin >> opt;

		/* todo:
					- check for characters
		*/
		if (opt < 0 || opt > 3) {
			cout << "Invalid option, please try again.";
		}
		else {
			valid = true;
		}
	}


	return 0;
}
