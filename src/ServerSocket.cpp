#include "ServerSocket.h"

int ServerSocket::CreateServer(int domain, int type, int port)
{
    socketId = socket(domain, type, 0); //This call results in a stream socket with the TCP protocol providing the underlying communication
    if (socketId == INVALID)
    {
        cerr << "Can't Create a Socket! Quitting" << endl;
        return -1;
    }
//MemorySet
    memset(Buffer,0,120);
    //Bind an Ip address and port to a socket
    sockaddr_in SOC;                                       //Creating an Object (Struc sockaddr_in)
    SOC.sin_family = domain;                               // Type of addresses that a socket can communicate with
    SOC.sin_port = htons(port); 
    SOC.sin_addr.s_addr= INADDR_ANY ;                       // Port Number
   // inet_pton(AF_INET, "127.0.0.1", &SOC.sin_addr.s_addr); //Your connection will accept all incoming addresses, in our case we are specifying to accept localhost
    if (bind(socketId, (sockaddr *)&SOC, sizeof(SOC)) < 0)
    {
        cerr << "Error : couldn't connect to server !!" << endl;
        return INVALID;
    }
    //listening

    std::cout << "Listnening for CLients ...  \n\n"
              << std::endl;

    if (listen(socketId, 2) < 0)
    {
        std::cout << "Error : listening failed !!" << std::endl;
        return INVALID;
    }
    std::cout << "Listnening for CLients  Done...  \n\n"
              << std::endl;
    //Accept
    int addressLength = sizeof(socketAdress);
    ClientSocket = accept(socketId, (struct sockaddr *)&socketAdress, (socklen_t *)&addressLength);
    if (ClientSocket < 0)
    {
        std::cout << "Error : connection failed !!" << std::endl;
        return INVALID;
    }

    std::cout << "Client Connected" << std::endl;
    return 1;
}


int ServerSocket::Receive()
{
    if (read(ClientSocket, Buffer, 100) <= 0)
    {
        std::cout << "Error : reception failed !!" << std::endl;
        return INVALID;
    }
    std::cout << "Recieving MESSAGE !!" << std::endl;

    std::cout << Buffer << std::endl;
    return 1;
}


int main()
{
    ServerSocket Soc;
    Soc.CreateServer(AF_INET, SOCK_STREAM, 50000);
    while (Soc.Receive() >= 1);
}


