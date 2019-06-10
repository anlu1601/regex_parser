
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
#include "chooser.h"
#include "characters.h"
#include "dot.h"
#include "plus.h"
#include "star.h"
#include "parentheses.h"

/*
 * <match> -> <expr>
 * <expr> -> <rep> | <or> | <id>
 * <id> -> <symbol> | <symbol><id>
 * <symbol> -> . | <char> | <char><symbol>
 * <char> -> [a-z]

 * // NEW GRAMMAR:
 * <program> -> <expression>
 * <expression> -> <capture> | <or> | <characters>
 * <capture> -> <expression>
 * <or> -> <characters> + <characters>
 * <characters> -> <char> | <char><symbol> | . | .<symbol>
 * <symbol> -> . | <star>
 * <star> -> <character>*
 * <char> -> [a-z]
 *  
 */

std::string matched = "";


struct token {
    enum id{
        ID, LEFT_PARENTHESES, RIGHT_PARENTHESES, DOT, CHAR, PLUS, STAR, END_PROGRAM
    };
    
    id id;
    std::string text;
};

using IT = std::string::iterator;
characters* chars(IT &first, IT &last);
op* expression(IT first, IT last);
op* parser(IT first, IT last);

    
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
        
        case '(':
            tk.id = token::LEFT_PARENTHESES;
            tk.text = "(";
        break;
        
        case ')':
            tk.id = token::RIGHT_PARENTHESES;
            tk.text = ")";
        break;
            
        
        default:
            tk.id = token::CHAR;
            tk.text = std::string(first, first + 1);
    }
    
    return tk;
}

parentheses* capture(IT &first, IT &last){
    parentheses* expr = new parentheses;
    
    expr->operands.push_back(chars(first, last));
    
    token tk = next_token(first, last);
       
    if(tk.id != token::LEFT_PARENTHESES){
        return nullptr;
    }

    first++;
    
//    std::cout << "PLUS:" << tk.id << "-" << tk.text << "\n";
    expr->_id = tk.text;
    expr->operands.push_back(expression(first, last));
    return expr;
}

star* repeat(IT &first, IT &last){
    
    std::string ch = "";
    ch = ch + *(first-1);
//    std::cout << ch << "\n";
    
    token tk = next_token(first, last);
    
    if(tk.id != token::STAR){
        return nullptr;
    }
    
    first++;
    
    star* expr = new star;
    expr->_id = tk.text;
    expr->_ch = ch;
//    std::cout << "REP:" << tk.id << "-" << tk.text << "\n";

    expr->operands.push_back(chars(first, last));
    return expr;
    
    
}

plus* either(IT first, IT last){
    plus* expr = new plus;
    expr->operands.push_back(chars(first, last));
    token tk = next_token(first, last);
       
    if(tk.id != token::PLUS){
        return nullptr;
    }

    first++;
    
//    std::cout << "PLUS:" << tk.id << "-" << tk.text << "\n";
    expr->_id = tk.text;
    expr->operands.push_back(expression(first, last));
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
//    std::cout << "DOT:" << tk.id << "-" << tk.text << "\n";<
    expr->operands.push_back(chars(first, last));
    return expr;
    
}

characters* chars(IT &first, IT &last){

    token tk = next_token(first, last);
    
//    std::cout << "\n" << tk.id << "=" << token::CHAR << "\n\n";

           
    
    if(tk.id == token::DOT){
        
        dot* expr = any(first, last);
        return expr;
    }
    
    if(tk.id == token::STAR){
        star* expr = repeat(first, last);
        return expr;
    }
    if(tk.id != token::RIGHT_PARENTHESES){
        if(tk.id != token::CHAR){
            return nullptr;
        }
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
    std::cout << tk.id << "-" << tk.text << "\n";
    expr->operands.push_back(chars(first, last));
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
    
    IT start = first;
    op* expr = capture(first, last);
    
    if(expr == nullptr){ 
        first = start;
        expr = either(first, last);
    }
    
    if(expr == nullptr){
        first = start;
        expr = chars(first, last);
    }
    
    chooser* choice = new chooser;
    choice->operands.push_back(expr);
    
    return choice;
    
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

void printTree(op* root, int level = 1){
    std::string pre = std::string("                                                                                                                                                                                                                 ", level*2);
    std::cout<< pre << root->id() << "\n";
    for(auto child:root->operands){
        if(child != nullptr)         
            printTree(child, level +1);
    }
}
/*
 * 
 */
int main(int argc, char** argv) {

    
    // This can be ".*"
//    std::string in = "WATERLOO(YOU+HELLO)";
//    std::string input = "WATERLOO HELLO THERE";
    
    std::string in = "W (A) T";
    std::string input = "W A T";
    
    
//    std::cout << *in.begin() << " " << *(in.end()-1) << "\n";
    
    
    op* res = parser(in.begin(), in.end());
    //std::cout << res->eval(input) << "\n";
    // This is Waterloo paragraf.
    printTree(res);
    
    if(res->eval(input)){
        std::cout << matched << std::endl;
    }else{
        std::cout << matched << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    /*
    auto b = in.begin();
    
    while(b != in.end()){
        tk = next_token(b, in.end());
        std::cout << "\n" << tk.text;
        b++;
    }*/
    
    return 0;
}

