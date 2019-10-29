#include <iostream>
#include <fstream>
using namespace std;

#define MAX_HEADLINE_LENGTH  60
#define MAX_DESCRIPTION_LENGTH  200
#define MAX_INSTRUCTION_LENGTH  200
void gen_cap()
{
	char headline[MAX_HEADLINE_LENGTH], description[MAX_DESCRIPTION_LENGTH], instr[MAX_INSTRUCTION_LENGTH];
	ofstream capFile;
	capFile.open("CAP.xml");

	int key_in;

	cout << "\nSelect Status\n";
	cout << "1: Actual\n";
	cout << "2: Exercise\n";
	cout << "3: System\n";
	cout << "4: Test\n";
	string status;
	cin >> key_in;
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

	cout << "\nSelect Message Type\n";
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

	cout << "\nEnter Disease Name\n";
	string disease;
	cin >> disease;
	
	
	cout << "\nSelect Location\n";

	cout << "1: Student Health Center\n";
	cout << "2: Nicholson\n";
	cout << "3: Lee\n";
	cout << "4: Perkins\n";
	int loc;
	cin >> loc;

	cout << "\nSelect Urgency\n";

	cout << "1: Immediate\n";
	cout << "2: Expected\n";
	cout << "3: Future\n";
	cout << "4: Past\n";
	cout << "5: Unknown\n";

	string urgency;
	cin >> key_in;
	switch(key_in)
	{
		case 1:
			urgency = "Immediate";
			break;
		case 2:
			urgency = "Expected";
			break;
		case 3:
			urgency = "Future";
			break;
		case 4:
			urgency = "Past";
			break;
		case 5:
			urgency = "Unknown";
			break;
		default:
			urgency = "Unknown";
			break;
	}

	cout << "\nSelect Severity\n";
	cout << "1: Extreme\n";
	cout << "2: Severe\n";
	cout << "3: Moderate\n";
	cout << "4: Minor\n";
	cout << "5: Unknown\n";
	string severity;
	cin >> key_in;
	switch(key_in)
	{
		case 1:
			severity = "Extreme";
			break;
		case 2:
			severity = "Severe";
			break;
		case 3:
			severity = "Moderate";
			break;
		case 4:
			severity = "Minor";
			break;
		case 5:
			severity = "Unknown";
			break;
		default:
			severity = "Unknown";
			break;
	}

	cout << "\nSelect Certainty\n";
	cout << "1: Observed\n";
	cout << "2: Likely\n";
	cout << "3: Possible\n";
	cout << "4: Unlikely\n";
	cout << "5: Unknown\n";

	string certainty;
	cin >> key_in;
	switch(key_in)
	{
		case 1:
			certainty = "Observed";
			break;
		case 2:
			certainty = "Likely";
			break;
		case 3:
			certainty = "Possible";
			break;
		case 4:
			certainty = "Unlikely";
			break;
		case 5:
			certainty = "Unknown";
			break;
		default:
			certainty = "Unknown";
			break;
	}
	cin.getline(headline, MAX_HEADLINE_LENGTH);
	cout << "\nEnter a Headline for the Alert\n";
	// string headline;
	cin.getline(headline, MAX_HEADLINE_LENGTH);
	
	cout << "\nEnter a Description for the Alert\n";
	// string description;
	cin.getline(description, MAX_DESCRIPTION_LENGTH);

	cout << "\nEnter a Set of Instructions for the Alert\n";
	// string instr;
	cin.getline(instr, MAX_INSTRUCTION_LENGTH);

	//Instantiate new time object
	time_t now = time(0);
	tm *ltm = localtime(&now);
	// string timestr = ltm->tm_year + "-" +ltm->tm_mon;
	// timestr += "-" + ltm->tm_mday + "T" + ltm->tm_hour;
	// timestr += ":" + ltm->tm_min + ":" + ltm->tm_min;
	// timestr += ":" + ltm->tm_sec;

	capFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	capFile << "<alert xmlns = \"urn:oasis:names:tc:emergency:cap:1.1\">\n";
	capFile << "<identifier></identifier>\n";
	capFile << "<sender></sender>\n";
	capFile << "<sent>" << ltm->tm_year+1900 << "-" << ltm->tm_mon+1
		<< "-" << ltm->tm_mday << "T" << ltm->tm_hour
	 	<< ":" << ltm->tm_min << ":" << ltm->tm_sec
		<< ":" << ltm->tm_gmtoff << "</sent>\n";
	capFile << "<status>" << status << "</status>\n";
	capFile << "<msgType>" << msg_type << "</msgType>\n";
	capFile << "<scope>Public</scope>\n";

	capFile << "<info>\n";
	capFile << "<category>Health</category>\n";
	capFile << "<event>" << disease << " Outbreak</event>\n";
	capFile << "<urgency>" << urgency << "</urgency>\n";
	capFile << "<severity>" << severity << "</severity>\n";
	capFile << "<certainty>" << certainty << "</certainty>\n";
	capFile << "<senderName></senderName>\n";
	capFile << "<headline>" << headline << "</headline>\n";
	capFile << "<description>" << description << "</description>\n";
	capFile << "<instruction>" << instr << "</instruction>\n";

	// capFile << msg << "\n";
	capFile << "</info>\n";

	capFile << "</alert>\n";	

	capFile.close();
}


int main() {
	gen_cap();
	return 0;
}