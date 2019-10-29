#include <iostream>
#include "user.hpp"

using namespace std;

void send(){
  user_menu();
}

void input_new(){
  user_menu();
}

void stats(){
  user_menu();
}

void send_msg(){
  user_menu();
}

void user_menu() {
  int opt = -1;
	bool valid = false;

	cout << "Select an Option\n";
	cout << "[0] - Back \n";
	cout << "[1] - Input New\n";
	cout << "[2] - User Registration\n";
	cout << "[3] - Statistics\n";
  cout << "[4] - Send Message\n";
	cout << "\n";

  cout << "Option:";
  cin >> opt;

	while(!valid){
		/* todo:
					- check for characters
          - fix flow bugs
		*/
		if (opt < 0 || opt > 4) {
			cout << "\nInvalid option, please try again." << endl;
      cout << "Option:";
  		cin >> opt;
		}
		else {
      switch(opt){
  			case 0: {
          valid = true;
  				break;
        }

  			case 1: {
  				input_new();
  				break;
  			}

  			case 2: {
  				stats();
  				break;
  			}

  			case 3: {
  				send_msg();
  				break;
  			}
  		}
			//
		}
	}
}
