#include <string>

namespace proto {
    enum TT {
        NIL,
        INT,
        FLOAT,
        PLUS,
        MINUS,
        MUL,
        DIV,
        MOD,
        LPAREN,
        RPAREN
    };

    class Token {
        public: 
                Token(TT type) :                         mType {type}, mNum {__null},mExpr {__null} {};
                Token(TT type, float num) :                  mType {type}, mNum{num},mExpr {__null} {};
                Token(TT type, float num, std::string expr) : mType {type}, mNum {num},mExpr {expr} {}; 


        private:
                TT mType; 
                float mNum;
                std::string mExpr;

    };
}