#ifndef TEST_HPP
#define TEST_HPP

#include"vcSERVER.hpp"


class test : public Server
{
public:
    test(int collectPort);
    void launch();

private:
    void Recieve();
    void Manage();
    void Send();

public:
    char buffer[30000]={0};
    int  newSocket;
private:

};




#endif
