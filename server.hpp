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

void srv_error(char *msg);

void SetupHospital(int port, string message);