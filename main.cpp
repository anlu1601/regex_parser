
/* 
 * File:   main.cpp
 * Author: anden
 *
 * Created on February 7, 2019, 10:44 AM
 */

#include <cstdlib>
#include <iosfwd>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "op.h"
#include "program.h"
#include "characters.h"
#include "dot.h"
#include "plus.h"

/*
 * <match> -> <expr>
 * <expr> -> <rep> | <or> | <id>
 * <id> -> <symbol> | <symbol><id>
 * <symbol> -> . | <char> | <char><symbol>
 * <char> -> [a-z]
 
 */

std::string matched = "";


struct token {
    enum id{
        ID, SYMBOL, DOT, CHAR, PLUS, STAR, END_PROGRAM
    };
    
    id id;
    std::string text;
};

using IT = std::string::iterator;
characters* chars(IT &first, IT &last);

token next_token(IT first, IT last){
    
    
    if(first == last){
       return token{token::END_PROGRAM, ""}; 
    }
    
    token tk;
     
    switch(*first){
        case '+':
            //std::cout << "PLUS";
            tk.id = token::PLUS;
            tk.text = "+";
            
        break;
        
        case '.':
            tk.id = token::DOT;
            tk.text = ".";
            
        break;
        
        case '*':
            //std::cout << "GÅNGER";
            tk.id = token::STAR;
            tk.text = "*";
        break;
        
        default:
            tk.id = token::CHAR;
            tk.text = std::string(first, first + 1);
    }
    
    return tk;
}

plus* either(IT &first, IT &last){
    token tk = next_token(first, last);
    
    if(tk.id != token::PLUS){
        return nullptr;
    }
    
    first++;
    
    plus* expr = new plus;
    expr->_id = tk.text;
    std::cout << "PLUS:" << tk.id << "-" << tk.text << "\n";
//    expr = chars(first, last);
    return expr;
    
}


dot* any(IT &first, IT &last){
    token tk = next_token(first, last);
        
    if(tk.id != token::DOT){
        return nullptr;
    }
    
    first++;
    
    dot* expr = new dot;
    expr->_id = tk.text;
//    std::cout << "DOT:" << tk.id << "-" << tk.text << "\n";
    expr->child = chars(first, last);
    return expr;
    
}

characters* chars(IT &first, IT &last){

    token tk = next_token(first, last);
    
//    std::cout << "\n" << tk.id << "=" << token::CHAR << "\n\n";
    
    if(tk.id == token::DOT){
        
        dot* expr = any(first, last);
        return expr;
    }
    
    if(tk.id != token::CHAR){
        return nullptr;
    }
    /*while(tk.id == token::CHAR){
        first++;
        character* expr = new character;
        expr->_id = tk.text;
        std::cout << tk.id << "-" << tk.text << "\n";
        tk = next_token(first, last);
        return expr;
    }*/
    
    first++;
    characters* expr = new characters;
    expr->_id = tk.text;
//    std::cout << tk.id << "-" << tk.text << "\n";
    expr->child = chars(first, last);
    return expr;
    
    
    
    
    
    
    //    if(*first == *last){
//        return nullptr;
//    }
//    
//    auto tk = next_token(first, last);
//    first++;
//    
//    if(*first != token::CHAR){
//        return nullptr;
//    }else{
//        return ;
//    }
//    return chars(first, last);
//    
}

op* expression(IT first, IT last){
    if(*first == *last){
        return nullptr;
    }
    
    op* expr = chars(first, last);
    
    
    
    
    return expr;
    
}

op* parser(IT first, IT last){
    
    if(*first == *last){
        return nullptr;
    }
    
    op* expr = expression(first, last);

    
    
//    if(!chars){
//        dot* expr = any(first, last);
//    }
    
    program* prog = new program;
    
   
    prog->operands.push_back(expr);
    return prog;

    //    
//    if(tk.id == token::PLUS){
//        parser(first, last);
//        std::cout << tk.text << std::endl;
//        return true;
//    
//    }else if(tk.id == token::CHAR){
//        parser(first, last);
//        std::cout << tk.text << std::endl;
//        return true;
//    }
//    return false;
//    
}

/*
 * 
 */
int main(int argc, char** argv) {

    
    // This can be ".*"
    std::string in = "WATER...";
    std::string input = "WATERLOO HELLO";
    
//    std::cout << *in.begin() << " " << *(in.end()-1) << "\n";
    
    
    op* res = parser(in.begin(), in.end());
    //std::cout << res->eval(input) << "\n";
    // This is Waterloo paragraf.
    if(res->eval(input))
        std::cout << matched << std::endl;
    else
        std::exit(EXIT_FAILURE);
    /*
    auto b = in.begin();
    
    while(b != in.end()){
        tk = next_token(b, in.end());
        std::cout << "\n" << tk.text;
        b++;
    }*/
    
    return 0;
}

