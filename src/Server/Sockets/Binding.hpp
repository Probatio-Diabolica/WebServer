#ifndef BINDING_HPP
#define BINDING_HPP
#include"Sockets.hpp"

class Binding: public Socket
{
public:
    Binding(int domain, int service,int protocol,int port,u_long interface);

private:
    int m_Connect(int sockDesc,sockaddr_in address);
};

#endif