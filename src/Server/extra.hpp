#include<string>

bool Check(const std::string& str)
{
    for(int i =0;i<str.length();i++)
    {
        if(str[i] < '0' or str[i]>'9') return false; 
    }
    return true;
}