/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
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
    int sockfd, newsockfd, portno; unsigned int clilen;
    char buffer[1000];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = port;
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    printf("Waiting on client to connect...\n");
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) 
          error("ERROR on accept");
    
    n = write(newsockfd,message.c_str(),message.size());
    if (n < 0) error("ERROR writing to socket");
    printf("Sent out CAP message!\n");
}

int main(int argc, char *argv[])
{
    std::ifstream t("file.txt");
    std::string input((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
    
    SetupHospital(atoi(argv[1]),input);
     return 0; 
}