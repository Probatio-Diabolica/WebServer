#ifndef SOCKETS_hpp
#define SOCKETS_hpp

#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
//Base class for our socket
class Socket
{
public:
    Socket(int domain,int service, int protocol,int port,u_long interface);
    void test_connection(int);
    sockaddr_in getAddress() const;
    int getSocketDescriptor() const;
    // int getConnection() const;
    void setConnection(int conn) ;
    virtual int m_Connect(int socketDescriptor, sockaddr_in address)=0;
private:
    //This calls bind internally
    


private:
    int m_socketDESC;
    sockaddr_in m_address;
    int m_connection;
public:

};


#endif
