#include"test.hpp"
#include<unistd.h>

test::test(int collectPort):Server(AF_INET,SOCK_STREAM,0,collectPort,INADDR_ANY,10)
{
    launch();
}

void test::launch()
{
    while(true)
    {
        std::cout<<"======WAITING==========\n";
        Recieve();
        Manage();
        Send();
        std::cout<<"======DONE============\n";
    }
}

void test::Recieve()
{
    sockaddr_in address = getSocket()->getAddress();
    int addrlen = sizeof(address);
    newSocket = accept(getSocket()->getSocketDescriptor(),(sockaddr* )&address,(socklen_t*)&addrlen);
    read(newSocket,buffer,30000);
}

void test::Manage()
{
    std::cout<<buffer<<'\n';
}

void test::Send()
{
    std::string testDATA="hello from server";
    write(newSocket,testDATA.data(),30000);
    close(newSocket);
}