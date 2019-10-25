#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream capFile;
	capFile.open("CAP.txt");
	capFile << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<rss version=\"2.0\">"
  <<"<channel><title>Amber Alert CAP Index</title><description>Amber Alert CAP Index</description>"
    <<"<link>http://www.missingkids.com/</link><pubDate>Wed, 11 Jun 2003 22:39:00 PDT</pubDate>"
    <<"<item><title>AMBER ALERT</title><description>DATE/TIME: 06/11/03, 1915 HRS.  VICTIM(S): KHAYRI DOE JR. M/B BLK/BRO 3'0\", 40 " 
<<"LBS. LIGHT COMPLEXION.  DOB 06/24/01. WEARING RED SHORTS, WHITE T-SHIRT, W/BLUE COLLAR."  
<<" LOCATION: 5721 DOE ST., LOS ANGELES, CA.  SUSPECT(S): KHAYRI DOE SR. DOB 04/18/71 M/B, BLK HAIR, "
<<"BRO EYE. VEHICLE: 81' BUICK 2-DR, BLUE (4XXX000).</description><link>http://cap-validator.appspot.com/examples/KAR0-0306112239-SW.cap</link>"
      <<"<guid>KAR0-0306112239-SW</guid><pubDate>Wed, 11 Jun 2003 22:39:00 PDT</pubDate></item></channel></rss>";
	capFile.close();
	return 0;
}

void gen_cap() {
	// cout << "Select Message Type\n";
	// cout << "1: Alert\n";
	// cout << "2: Update\n";
	// cout << "3: Error\n";
	// string msg_type;
	// cin >> msg_type;

	// cout << "Enter Disease Name\n";
	// string disease;
	// cin >> disease;
	
	// cout << "Select Location\n";
	// cout << "1: Student Health Center\n";
	// cout << "2: Nicholson\n";
	// cout << "3: Lee\n";
	// cout << "4: Perkins\n";
	// int loc;
	// cin >> loc;

	// cout << "Enter any additional information to include\n";
	// string msg;
	// cin >> msg;
	
	// capFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
	// capFile << "<alert>\n";

	// capFile << "<info>\n";
	// capFile << "<area>" << loc << "</area>\n;
	// capFile << msg << "\n";
	// capFile << "</info>\n";

	// capFile << "</alert>\n";	

}
