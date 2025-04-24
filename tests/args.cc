#include<iostream>
#include<string_view>
class a
{
public:
    inline void one(const std::string_view &s)
    {
        std::cout<<s;
    }
};

class B
{
public:
    void Two(const std::string_view &s)
    {
        std::cout<<s;
    }
};

class C
{
public:
    void Three(const std::string_view &s)
    {
        std::cout<<s;
    }
};

class D
{
public:
    void Four(const std::string_view &s)
    {
        std::cout<<s;
    }
};

class E:  a, B,public C,D
{
public:
    E()
    {
        one("ONE\n");
        Two("TWO\n");
        Three("THREE\n");
        Four("FOUR\n");
    }
};



int main(int argc , char** argv)
{
    E a =E();
    std::cout<<argc << " || "<<argv[1]<<"\n"; 
}