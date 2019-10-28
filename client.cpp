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
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1000];
    portno = port;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(hostname.c_str());
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    int bytes = 10000;
    string output(bytes,0);
    if(read(sockfd,&output[0],bytes-1) < 0){
        cout << "Error: Failed to read from socket" << endl;
        return;
    }
    cout << output << endl;

    ofstream outFile("message.txt");
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
    ConnectToUser(argv[1], atoi(argv[2]));
    
    return 0;
}