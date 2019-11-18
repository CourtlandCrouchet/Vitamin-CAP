/*
Author(s): Raphaela, JJ
Updated: 11/16/19
Description: User interface post-authentication
*/
#include <iostream>
#include "user.hpp"
#include "cap_gen.hpp"
#include "server.hpp"
#include "db_functions.hpp"

using namespace std;

void delete_user(){
  string sql;
  int id;
  sql = "select * from users;";
  sql_select(sql);
  sql = "";

  cout<<"Enter user id to be deleted:";
  cin >> id;
  _delete("users",id);
  user_mgmt();
}

void update_user(){
  string sql, table, field, value;
  int id;
  cout<<"Enter table name:";
  cin >> table;
  sql = "select * from " + table + ";";
  sql_select(sql);
  cout<<"Enter user id to be updated:";
  cin >> id;
  cout<<"Enter field to be updated:";
  cin >> field;
  cout<<"Enter new value:";
  cin >> value;
  sql_update(table,field, value, id);
  user_mgmt();
}

void list_users(){
  string sql;
  sql = "select * from users;";
  sql_select(sql);
  user_mgmt();
}

void user_mgmt(){
  int opt;
  //bool valid = false;
  cout << "\n";
  cout << "Select an Option\n";
  cout << "[0] - Back \n";
  cout << "[1] - Delete User\n";
  cout << "[2] - Update User\n";
  cout << "[3] - List Users\n";
  cout << "\n";
  /* todo:
        - check for characters
        - fix flow bugs
  */
  cout << "Option: ";
  cin >> opt;

  switch(opt){
    case 0: {
      user_menu();
      //valid = true;
      break;
    }

    case 1: {
      delete_user();
      break;
    }

    case 2: {
      update_user();
      break;
    }

    case 3: {
      list_users();
      break;
    }

    default: {
      cout << "\nInvalid option." << endl;
      user_mgmt();
    }
  } //switch
  //opt = -1;
  //user_menu();
}

void stats(){
  string sql;

  cout << "Count diseases and orders them by DESC" << endl;
  sql = "SELECT name,count(name) from Diagnoses , Diseases WHERE diseases.id = diagnoses.DiseaseID GROUP BY name ORDER BY count(name) desc;";
  sql_select(sql);
  cout << "\n";

  cout << "Return username and the number of diagnoses inputed" << endl;
  sql = "SELECT username, count(diagnoses.userID) FROM users, diagnoses WHERE users.id = diagnoses.userID GROUP BY diagnoses.userID;";
  sql_select(sql);
  cout << "\n";

  cout << "Returns the disease within the last 7 days with the count" << endl;
  sql = "SELECT name , count(diagnoses.diseaseID) FROM diseases, diagnoses WHERE diagnoseDate > (SELECT DATE('now','-7 day')) AND diagnoses.diseaseID=diseases.id GROUP BY diagnoses.diseaseID;";
  sql_select(sql);
  cout << "\n";

  user_menu();
}

void input_new(){
  new_menu();
  user_menu();
}

void new_diagnose(){
  string sql, query;

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
  string sql, query;

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
	//bool valid = false;

//	while(!valid){

    cout << "\n";
  	cout << "Select an Option\n";
  	cout << "[0] - Back \n";
  	cout << "[1] - New Diagnose\n";
  	cout << "[2] - New Disease\n";
  	cout << "\n";
		/* todo:
					- check for characters
          - fix flow bugs
		*/
    cout << "Option: ";
    cin >> opt;

    switch(opt){
			case 0: {
        //valid = true;
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
        new_menu();
      }
		} //switch
    //opt = -1;
	//}//while
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
	//bool valid = false;

  // cout << "Option:";
  // cin >> opt;

//	while(!valid){
    cout << "\n";
  	cout << "Select an Option\n";
  	cout << "[0] - Back \n";
  	cout << "[1] - Input New\n";
  	cout << "[2] - Statistics\n";
    cout << "[3] - Send Message\n";
    cout << "[4] - User Management\n";
  	cout << "\n";
		/* todo:
					- check for characters
          - fix flow bugs
		*/
    cout << "Option: ";
    cin >> opt;

    switch(opt){
			case 0: {
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

      case 4: {
				user_mgmt();
				break;
			}

      default: {
        cout << "\nInvalid option, please try again." << endl;
        user_menu();
      }
		} //switch
	//}//while
}
