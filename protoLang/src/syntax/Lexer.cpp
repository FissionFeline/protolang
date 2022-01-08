#include "Lexer.hpp"
#include <iostream>

namespace proto {
    bool Lexer::isAlpha(char c)       { return (c >= 'a' && c <='z') || (c >= 'A' && c <= 'Z'); }
    bool Lexer::isDigit(char c)       {return (c >= '0' && c <= '9'); }
    bool Lexer::isWhitespace(char c)  {return (c == ' ' || c == '\t' || c == '\n'); }
    bool Lexer::isOperator(char c)    {return (c == '+' || c=='/' || c == '%' || c == '-' || c == '*');}

    bool Lexer::has() {  return mIndex < mInput.length(); }
    
    void Lexer::advance() { mIndex++; }

    char Lexer::peekChar() { return mInput.at(mIndex); }

    
    
    std::vector<Token> Lexer::tokenize() {
        std::vector<Token> tokens;

        while (has()) {
            if (isWhitespace(peekChar())) {
                advance(); 
            } else if (isDigit(peekChar()) || peekChar() == '.') {
                auto start = mIndex;
                TT typeToSet; 
                bool setType = true; 

                while(has() && (isDigit(peekChar()) || peekChar() == '.')) {
                    if (setType) {
                        if (peekChar() == '.') { typeToSet = TT::FLOAT; setType = false; } else { typeToSet = TT::INT; }
                    }
                    advance();
                }
                    std::cout<<(typeToSet == TT::INT ? "INT IS " : "FLOAT IS ");
                    std::cout<<(typeToSet == TT::INT ? std::atoi(mInput.substr(start,mIndex).c_str()) : std::atof(mInput.substr(start,mIndex).c_str()))<<std::endl;
                    tokens.push_back(Token(typeToSet,(typeToSet == TT::INT ? std::atoi(mInput.substr(start,mIndex).c_str()) : std::atof(mInput.substr(start,mIndex).c_str()))));
            } else if (isOperator(peekChar())) {
                
                switch (peekChar())
                {
                    case '+' :
                                tokens.push_back(Token(TT::PLUS));
                                break;
                    case '-' :
                                tokens.push_back(Token(TT::MINUS));
                                break;
                    case '*' : 
                                tokens.push_back(Token(TT::MUL));
                    case '/' : 
                                tokens.push_back(Token(TT::DIV));
                    case '%' : 
                                tokens.push_back(Token(TT::MOD));
                }
                std::cout<<"OPERATOR ";
                std::cout<<peekChar()<<std::endl;
                advance();
            } else {
                std::cout<<"ERROR UNSUPPORTED TOKEN: ";
                std::cout<<peekChar(); 
                std::cout<<" DETECTED"<<std::endl;
                advance();
            }
        }

        return tokens;
    }
}