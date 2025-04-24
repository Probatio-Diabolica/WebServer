#include "Connecting.hpp"


Connecting::Connecting(int domain, int service, int protocol, int port, u_long interface)
    : Socket(domain, service, protocol, port, interface)
{
    setConnection(m_Connect(getSocketDescriptor(),getAddress()));
    test_connection(getSocketDescriptor());
}


int Connecting::m_Connect(int sockDesc, sockaddr_in address)
{
    return connect(sockDesc,(sockaddr *)& address,sizeof(address));
}
