#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream capFile;
	capFile.open("CAP.txt");
	capFile << "Hello World";
	capFile.close();
	return 0;
}

void gen_cap() {
	cout << "Select Message Type\n";
	cout << "1: Alert\n";
	cout << "2: Update\n";
	cout << "3: Error\n";
	string msg_type;
	cin >> msg_type;

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
	capFile << "<alert>\n";

	capFile << "<info>\n";
	capFile << "<area>" << loc << "</area>\n;
	capFile << msg << "\n";
	capFile << "</info>\n";

	capFile << "</alert>\n";	
}
