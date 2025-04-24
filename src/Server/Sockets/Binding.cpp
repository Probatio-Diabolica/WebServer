#include "Binding.hpp"


//Inits the web Socket
Binding::Binding(int domain, int service, int protocol, int port, u_long interface)
    : Socket(domain,service,protocol,port,interface)
{
    setConnection(m_Connect(getSocketDescriptor(),getAddress()));
    test_connection(getSocketDescriptor());
}

//Actually establishes the connection by Binding.
/// @brief All it does it to associate a socket(descriptor) with a specific local address and a portnumber
/// @returns >  ```0``` in success and ```-1``` in case of a failure
int Binding::m_Connect(int sockDesc, sockaddr_in address)
{
    return bind(sockDesc,(sockaddr *)&address,sizeof(address));
}


