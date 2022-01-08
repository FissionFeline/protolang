#include "token.hpp"
#include <vector>

namespace proto {

    class Lexer {
        public :
                Lexer(std::string input) : mInput {input} , mIndex {0} {};

                std::vector<Token> tokenize();


        private: 
                bool isWhitespace(char c); 
                bool      isDigit(char c); 
                bool      isAlpha(char c);
                bool      isOperator(char c);
                
                bool has();

                char peekChar();

                void advance(); 


                size_t mIndex;
                std::string mInput; 
                


    };

}