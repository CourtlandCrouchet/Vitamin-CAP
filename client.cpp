#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>

using namespace std;
void error(char *msg)
{
    perror(msg);
    exit(0);
}

void ConnectToUser(string hostname, int port){
    int sockfd, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;
    //Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    //Check if server exists
    server = gethostbyname(hostname.c_str());
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    //clear out server address info and set the values
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(port);
    //connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    //Set large upper bound for size of message to be recieved
    int bytes = 10000;
    string output;
    output.resize(bytes);

    int bytes_got =  read(sockfd,&output[0],bytes-1);
    if( bytes_got < 0){
        cout << "Error: Failed to read from socket" << endl;
        return;
    }
    //trim any unused bytes from string
    output.resize(bytes_got);
    //write output to file
    ofstream outFile("CAP.xml");
    if(outFile.is_open()){
        outFile << output;
        outFile.close();
    }

}

int main(int argc, char *argv[])
{
    
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    // Function takes an IP address and port no
    ConnectToUser(argv[1], atoi(argv[2]));
    
    return 0;
}