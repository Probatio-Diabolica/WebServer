// #include<thread>
#include<iostream>
#include<string>
#include"Server/extra.hpp"
#include"Server/test.hpp"



// To run this webserver do : 'localhost:portname'
int main(int argc, char **argv) {

    int port;
    if(argc < 2)
    {
        std::cout<<"Less arguments provided :: \nDefault port set to 2005\n";
        port = 2005;
    }
    else
    {
        if(Check(argv[1]))
        {
            port=std::stoi(argv[1]);
        }else
        {
            std::cout<<"Arg is not a valid port number:: Default port set to 2005\n";
            port =2005;
        }
    }
    // Server serv=Server();
    

    // serv.run();
    test t = test(port);

    return 0;
}
