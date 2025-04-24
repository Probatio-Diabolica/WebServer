#include "Sockets.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief This ```Default``` Function creates a socket which uses the following params :
/// @param domain > The domain that is used (e.g., AF_INET for IPv4, AF_INET6 for IPv6).
/// @param service  >  The type of service being used (e.g., SOCK_STREAM for TCP, SOCK_DGRAM for UDP).
/// @param protocol > The protocol to be used (typically 0 to use the default for the given service).
/// @param port > The port number to be used.
/// @param interface > The IP address to bind the socket to (use INADDR_ANY to bind to all interfaces).
/// @details This constructor initializes the socket descriptor and sets up the address structure for the socket. The Address structure includes the domain, port (converted o network bute order using htons()) and the IP address (converted back to byte order ust=ing htonl()).
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Socket::Socket(int domain, int service, int protocol,int port,u_long interface)
    :m_socketDESC(socket(domain,service,protocol))
{
    m_address.sin_family=domain;
    //// htons() host to network short
    m_address.sin_port= htons(port);
    m_address.sin_addr.s_addr=htonl(interface);
    //// ESTABLISHING A SOCKET 
    m_socketDESC = socket(domain,service,protocol);
    
    ////let's test this big boi
    test_connection(m_socketDESC);
}

void Socket::test_connection(int testItem)
{
    static int times;
    //// A socket descriptor returns -1 if it fails to get a socket permission from the kernal
    if(testItem<0) 
    {
        std::cerr<<testItem<<"failed to connect...\n";
        exit(EXIT_FAILURE);
    }
    std::cout<<"Success RATE :: "<<++times<<'\n';
}



///////////////////////////////////////////////////// Getters /////////////////////////


sockaddr_in Socket::getAddress() const
{
    return m_address;
}

int Socket::getSocketDescriptor() const
{
    return m_socketDESC;
}



///////////////////////////////////////// setters //////////////////////////// 

//sets the connection
void Socket::setConnection(int conn)
{
    m_connection = conn;
}
