#include "syntax/Lexer.hpp"
#include <iostream>


int main()
{
    std::cout<<"ProtoShell v0.0.1"<<std::endl;
    std::cout<<"Enter a test token"<<std::endl;
    std::string test; 
    std::getline(std::cin,test);
    std::cout<<"TEST TOKEN "<<test<<std::endl;
    auto l = proto::Lexer(test);
    auto tokens = l.tokenize();
    return 0;
}