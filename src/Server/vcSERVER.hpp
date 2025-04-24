#ifndef SERVER_HPP
#define SERVER_HPP
#include<memory>

#include "SOCK.hpp"

#include"Clients.hpp"
class Server
{
public:
    Server(int domain, int service,int protocol ,int port ,u_long interface,int limit);
    void run();
    
    const std::shared_ptr<Listener> getSocket() const   ;

    ~Server();

    
    //!! Bunch of deletes ------------------------------------------------------------------------------------------------
    Server(Server& copy) = delete;
    Server(const Server& copy) = delete;
    Server(const Server&& move) = delete;
    Server& operator =(const Server& copy) = delete;
    Server& operator=(const Server&& copy) = delete;


    virtual void Recieve() = 0;
    virtual void Manage() = 0;
    virtual void Send() = 0;

private:
    // virtual void m_Recieve() = 0;
    // virtual void m_Manage() = 0;
    // virtual void m_Send() = 0; 
private:
    int m_port;
    Clients m_clientList[100];
    int m_responses[100];
    int m_socket;
    std::shared_ptr<Listener> m_listener;
};

#endif
