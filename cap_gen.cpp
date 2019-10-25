#include <iostream>
#include <fstream>
using namespace std;

int main() {
	
	return 0;
}
string gen_cap()
{
	ofstream capFile;
	capFile.open("CAP.txt");

	int key_in;

	cout << "Select Status\n";
	cout << "1: Actual\n";
	cout << "2: Exercise\n";
	cout << "3: System\n";
	cout << "4: Test\n";
	string status;
	cint >> key_in;
	switch (key_in)
	{
		case 1:
			status = "Actual";
			break;
		case 2:
			status = "Exercise";
			break;
		case 3:
			status = "System";
			break;
		case 4:
			status = "Test";
			break;
		default:
			status = "Test";
			break;
	}

	cout << "Select Message Type\n";
	cout << "1: Alert\n";
	cout << "2: Update\n";
	cout << "3: Error\n";
	string msg_type;
	cin >> key_in;
	switch (key_in)
	{
		case 1:
			msg_type = "Alert";
			break;
		case 2:
			msg_type = "Update";
			break;
		case 3:
			msg_type = "Error";
			break;
		default:
			msg_type = "Error";
			break;
	}

	cout << "Enter Disease Name\n";
	string disease;
	cin >> disease;
	
	cout << "Select Location\n";
	cout << "1: Student Health Center\n";
	cout << "2: Nicholson\n";
	cout << "3: Lee\n";
	cout << "4: Perkins\n";
	int loc;
	cin >> loc;

	cout << "Enter any additional information to include\n";
	string msg;
	cin >> msg;
	
	capFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	capFile << "<schema xmlns = \"http://www.w3.org/2001/XMLSchema\"\n";
	capFile << "<alert>\n";
	capFile << "<identifier></identifier>\n";
	capFile << "<sender></sender>\n";
	capFile << "<sent></sent>\n";
	capFile << "<status>" << status << "</status>\n";
	capFile << "<info>\n";
	capFile << "<area>" << loc << "</area>\n";
	capFile << msg << "\n";
	capFile << "</info>\n";

	capFile << "</alert>\n";	

	capFile.close();
}
