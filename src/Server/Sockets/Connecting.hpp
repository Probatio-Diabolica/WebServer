#pragma once
#include "Sockets.hpp"
class Connecting:public Socket
{
private:
    int m_Connect(int sockDesc,sockaddr_in address);
public:
    Connecting(int domain, int service, int protocol, int port, u_long interface);
};


