#include <sys/socket.h>
#include <netinet/in.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <arpa/inet.h>
#include <string.h>


#define INVALID -1 

using namespace std ;




class ServerSocket

{
    private:
    int port;
    int domain;
    int type;
    int protocol;
    sockaddr_in socketAdress;
public:
    int socketId;
    int ClientSocket;
    char Buffer[120];
public:
    int CreateServer(int domain,int type,int port);
    void Close();
    int Receive();
} ;

