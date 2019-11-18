#include <iostream>
#include "user.hpp"
#include "cap_gen.hpp"
#include "server.hpp"
#include "db_functions.hpp"

using namespace std;

void input_new(){
  new_menu();
  user_menu();
}

void new_diagnose(){
  string sql;
  string query;

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
}

void new_disease(){
  string sql;
  string query;

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
}

void new_menu(){
  int opt = -1;
	bool valid = false;

  cout << "\n";
	cout << "Select an Option\n";
	cout << "[0] - Back \n";
	cout << "[1] - New Diagnose\n";
	cout << "[2] - New Disease\n";
	cout << "\n";

	while(!valid){
		/* todo:
					- check for characters
          - fix flow bugs
		*/
    cout << "Option: ";
    cin >> opt;

    switch(opt){
			case 0: {
        valid = true;
				break;
      }

			case 1: {
				new_diagnose();
				break;
			}

			case 2: {
				new_disease();
				break;
			}

      default: {
        cout << "\nInvalid option, please try again." << endl;
      }
		} //switch
	}//while
}

void stats(){
  user_menu();
}

void send_msg(){
  int port = 49999;
  gen_cap();
  ifstream t("CAP.xml");
  string input((istreambuf_iterator<char>(t)),
  istreambuf_iterator<char>());
  //Function accepts a port no and a message to send
  SetupHospital(port,input);
  user_menu();
}

void user_menu() {
  int opt = -1;
	bool valid = false;

  cout << "\n";
	cout << "Select an Option\n";
	cout << "[0] - Back \n";
	cout << "[1] - Input New\n";
	cout << "[2] - Statistics\n";
  cout << "[3] - Send Message\n";
	cout << "\n";

  // cout << "Option:";
  // cin >> opt;

	while(!valid){
		/* todo:
					- check for characters
          - fix flow bugs
		*/
    cout << "Option: ";
    cin >> opt;

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

      default: {
        cout << "\nInvalid option, please try again." << endl;
      }
		} //switch
	}//while
}