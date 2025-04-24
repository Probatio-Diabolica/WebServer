#include "vcSERVER.hpp"



Server::Server(int domain, int service, int protocol, int port, u_long interface, int limit)
    : m_port(port)
{
    std::cout<<"Server started at ..."<<port<<"\n";
    m_listener = std::make_shared<Listener>(domain,service,protocol,port, interface,limit);
}


void Server::run()
{
    std::cout<< "Binding sock :: \n" ;
    Binding bin = Binding(AF_INET,SOCK_STREAM,0,m_port,INADDR_ANY);
    std::cout<<" Listening :: \n";
    Listener bin2 = Listener(AF_INET,SOCK_STREAM,0,m_port,INADDR_ANY,10);
    // std::cout<<" Listening :: \n";
}

const std::shared_ptr<Listener> Server::getSocket() const
{
    return m_listener;
}

Server::~Server()
{
    // close(m_socket);
}
