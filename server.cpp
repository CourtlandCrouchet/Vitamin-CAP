#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include<bits/stdc++.h> 

using namespace std;

void error(char *msg)
{
    perror(msg);
    exit(1);
}

void SetupHospital(int port, string message){
    int sockfd, newsockfd; unsigned int clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    //create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    //initialize server address and fill in the values
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);
    //Bind the socket to a port
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) 
            error("ERROR on binding");
    //listen for client connection on the port
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    printf("Waiting on client to connect...\n");
    //accept a connection from client
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
          error("ERROR on accept");
    // send message over established connection
    n = write(newsockfd,message.c_str(),message.size());
    if (n < 0) error("ERROR writing to socket");
    printf("Sent out CAP message!\n");
}

int main(int argc, char *argv[])
{
    //Read from a file and put it in a string
    std::ifstream t("file.txt");
    std::string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    //Function accepts a port no and a message to send
    SetupHospital(atoi(argv[1]),input);
    return 0; 
}