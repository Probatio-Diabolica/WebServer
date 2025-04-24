#ifndef LISTENER_HPP
#define LISTENER_HPP
#include "Binding.hpp"

class Listener : public Binding
{
public:
    Listener(int domain, int service,int protocol ,int port ,u_long interface,int limit);
    void start();
    int getListener() const;
    int getLimit() const;
private:
    int m_backlog;
    int m_listen;
};
#endif