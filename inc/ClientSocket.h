#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define INVALID -1 

using namespace std ;




class ClientSocket

{
    private:
    int port;
    int domain;
    int type;
    int protocol;
    sockaddr_in socketAdress;
    uint32_t adress ;
public:
    int socketId;
    int ServerSocket;
    char Buffer[120];
public:
    int CreateClient(int domain,int type,int port);
    int Send(const char * Buffer);
} ;
