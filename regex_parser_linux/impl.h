
#ifndef IMPL_H
#define IMPL_H

#include <vector>
#include <string>

/*
 * // NEWEST GRAMMAR
 * <program> -> <expression>
 * <expression> -> <capture>[<expression>] | <or> | <characters>[<expression>]
 * <capture> -> <expression>
 * <or> -> <characters> + <characters>
 * <characters> -> <char>[<symbol>] | <dot>[<symbol>]
 * <symbol> -> <dot> | <star>
 * <star> -> <character>*
 * <char> -> [a-z]
 * <dot> -> .
 */

std::vector<std::string> captures;
extern std::string matched;


struct op {
    virtual bool eval(char* &begin, char* end) = 0;
    std::vector<op*> operands;

};

// <program> -> <expression>
struct program:op{
    bool eval(char* &begin, char* end){
        for (int b = begin; b != end; b++) {
            if(operands[0]->eval(b, end) == false){
                    return false;
                }
                return true;
            }

        }

    
//    op* expression;

};

// * <expression> -> <capture>[<expression>] | <or> | <characters>[<expression>]
struct expression:op{
    bool eval(char* &begin, char* end){
        if(operands[0]->eval(begin, end) == false){
            return false;
        }
        if(operands[1] != nullptr){
            return operands[1]->eval(begin, end);
        }
    }
//    op* or_or_cap;
//    op* next_expression_optional;
};

//<capture> -> <expression>
struct capture:op{
    bool eval(char*& begin, char* end){
        
        std::string current_matched = matched;
        begin++;
        
        if(operands[0]->eval(begin, end) == false){
            return false;
        }
        
        captures.push_back(diff(current_matched, matched));
        
        return true;
    }
    
//    op* expression;
};

std::string diff(std::string cm, std::string m){
    std::size_t found;
    
    found = m.find(cm);
    if(found != std::string::npos)
        return m.substr(0, found);
    return "0";
    
}

// <characters> -> <char>[<symbol>] | <dot>[<symbol>]
struct characters:op{
    bool eval(char*& begin, char* end){
        for (int b = begin; b != end; b++) {
            if(operands[0]->eval(begin, end) == false){
                return false;
            }
        }
        if(operands[1] != nullptr){
            return operands[1]->eval(begin, end);
        }

    }
//    op* chars_or_dot;
//    op* symbol_optional;
};


struct chars_or_dot:op{
    chars(char c):c(c){}
    
    bool eval(char* &begin, char* end){
        if(*begin == c || c == "."){
            matched = matched + *begin;
            begin++;
            return true;
        }
        return false;
    }
    
    char c;
};


#endif /* IMPL_H */

