#include <iostream>
using namespace std;
bool successful = true;

class loginAttempt{
public:
string usernameTest;
string passwordTest;
string username = "Michael_Tiger1";
string password = "LSU123!";

public: 
loginAttempt(){
	cout << "Please enter your user name: ";
	cin >> usernameTest;
	if(usernameTest.compare(username) == 0){
		cout << "Please enter your password : ";
		cin >> passwordTest;
		if(passwordTest.compare(password) == 0){
			cout << "Welcome to our system. \n";
		}
		else if(usernameTest.compare(username) == 1){
			cout << "Incorrect Login, Please Try Again \n";
			successful = false;

		}
		else if (passwordTest.compare(password) == 1){
			cout << "Incorrect Password, Please Try Again \n";
			successful = false;
		}
	}

}
};

int main() {
	
  int consoleChoice = 0;
  
  while(consoleChoice != 6){
    
    switch(consoleChoice){
			successful = false;

      case 0:
      break;

      case 1: 
			if(successful == true){
			loginAttempt();
			}
			else if(successful == false){
				cout << "Failed Attempt, Goodbye \n";
				return 0;
			}
			else{
				return 0;
			}
      break;

      case 2:
      cout<<"Registration User Page Here: \n";
      cout<<"Register user things here: \n";
      break;

      case 3:
      cout<<"Register Out Break Case Here: \n";
      cout<<"Register cases here: \n";
      break;

      case 4:
      cout<<"Send Out Break Information Here: \n";
      cout<<"People are dying and the world should know \n";
      break;
    
      case 5:
      cout << "thanks for testing\n";
      return 0;


      default: cout<<"Error: Not Valid Selection:\n ";
      cout<<"you done messed up a-a-ron \n";
      break;
    }
    
    cout<< "Test Application V1 \n";
    cout<< "Select an Option\n";
    cout<< "[1] - User Login\n";
    cout<< "[2] - User Registration\n";
    cout<< "[3] - Break Out Case Log\n";
    cout<< "[4] - Send Correspondence\n"; 
    cout<<"[5] - Quit Application: \n";
    cout<<"\n";
    cin>> consoleChoice;
  }
  return 0;
}

/*
 Come up with the scenario for the demontration of the system
 */
