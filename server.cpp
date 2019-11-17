// Author: Afolabi
// Updated: 17-Nov-2019
// Description: Setup a server that can send a message to multiple clients
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <bits/stdc++.h>
#include <pthread.h>
#include <iostream>
#include <arpa/inet.h>

using namespace std;

void error(string msg)
{
    perror(msg.c_str());
    exit(1);
}

struct Client{
    int fd;
    char ip[INET_ADDRSTRLEN];
    unsigned short port;
    string message;
};

void *Thread(void *args) {
    Client *clientinfo=(Client *)args;
    pthread_t myid=pthread_self();
    printf("Thread %p is alive and serving new client @ %s:%d\n",myid, clientinfo->ip, clientinfo->port);
    //Send message to client
    write(clientinfo->fd, clientinfo->message.c_str(), clientinfo->message.size());
    printf("Thread %p closed connection with client, dying.\n", myid);
    free(args);
    printf("Press q to quit or any other key to accept more clients\n");
    return NULL;
}

void SetupHospital(int port, string message){
    int sockfd, newsockfd; unsigned int clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char in;
    pthread_t client_thread;
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
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            error("ERROR on binding");
    //listen for client connection on the port
    listen(sockfd,20);


    while(1){
        Client* customer = new Client;
        cout << "Now accepting clients..." << endl;
        //Clear out space for client
        bzero(&cli_addr, sizeof(cli_addr));
        clilen = sizeof(cli_addr);
        //accept a connection from client
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        //Get client IP address
        inet_ntop(AF_INET, &(cli_addr.sin_addr), customer->ip, INET_ADDRSTRLEN);
        //Set relevant client info to be passed to thread
        customer->port=cli_addr.sin_port;
        customer->fd=newsockfd;
        customer->message=message;
        //Create thread and pass all info to it
        pthread_create(&client_thread, NULL, Thread, customer);
        //option to quit
        cin >> in;
        if(in == 'q'){
            return;
        }
    }
}

// int main(int argc, char *argv[])
// {
//     //Function accepts a message to send
//     SetupHospital(atoi(argv[1]),"Testing 1,2");
//     return 0;
// }
