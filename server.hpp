/*
Author(s): Raphaela
Updated: 10/20/19
Description: Main program of the application
*/
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

void error(char *msg);

void SetupHospital(int port, string message);
