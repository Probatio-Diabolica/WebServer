#include "Lisenter.hpp"
// #include<iostream>
Listener::Listener(int domain, int service, int protocol, int port, u_long interface, int limit) 
    : Binding(domain,service,protocol,port,interface)
{
    m_backlog = limit;
    start();
    test_connection(m_listen);
}

void Listener::start()
{
    m_listen=listen(getSocketDescriptor(),m_backlog);
}

int Listener::getListener() const
{
    return m_listen;
}

int Listener::getLimit() const
{
    return m_backlog;
}
