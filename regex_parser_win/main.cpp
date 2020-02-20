
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
#include <functional>
#include "op.h"
#include "program.h"
#include "expression.h"
#include "one_expr.h"
#include "string_expr.h"
#include "or_expr.h"
//#include "chooser.h"
//#include "characters.h"
//#include "dot.h"
//#include "plus.h"
//#include "star.h"
//#include "parentheses.h"

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
 * 
 * // NEWER GRAMMAR:
 * <program> -> <expression>
 * <expression> -> <expr> | <expr_again>
 * <expr_again> -> <expr><expr_again>
 * <expr> -> <or> | <string>
 * <or> -> <string> + <string>
 * <string> -> chars
 * 
 */

std::string matched = "";
std::vector<std::string> captures;
IT begin_of_match;

struct token {
    enum id{
        ID, LEFT_PARENTHESES, RIGHT_PARENTHESES, DOT, CHAR, OR, STAR, END_PROGRAM
    };
    
    id id;
    std::string text;
};

using IT = std::string::iterator;
//characters* chars(IT &first, IT &last);
op* get_expression(IT &first, IT &last);
op* parser(IT &first, IT& last);
op* get_one_expr(IT &first, IT &last);
op* get_string_expr(IT &first, IT &last);
op* make_or_expr(IT &first, IT &last);
op* make_more_exprs(IT &first, IT &last);
void print_ast_tree(op*& o, int i);
    
token next_token(IT& first, IT& last){
    
    
    if(first == last){
       return token{token::END_PROGRAM, ""}; 
    }
    
    token tk;
     
    switch(*first){
        case '+':
            //std::cout << "PLUS";
            tk.id = token::OR;
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
/*
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
    
    if(tk.id != token::RIGHT_PARENTHESES){
        return nullptr;
    }
    
    first++;
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
    
}*/
/*
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
    /*
    first++;
    characters* expr = new characters;
    expr->_id = tk.text;
//    std::cout << tk.id << "-" << tk.text << "\n";
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
*/

op* make_or_expr(IT &first, IT &last){
    if(first == last){
        return nullptr;
    }
    
    IT start = first;
    
    op* lhs_expr = get_string_expr(first, last);
    if(!lhs_expr){
        first = start;
        return nullptr;
    }
    
    token tk = next_token(first, last);
    if(tk.id != token::OR){
        first = start;
        return nullptr;
    }
    
    first++;
    
    op* rhs_expr = get_string_expr(first, last);
    if(!rhs_expr){
        first = start;
        return nullptr;
    }
    
    or_expr* or_ex = new or_expr;
    
    or_ex->lhs = lhs_expr->id();
    or_ex->rhs = rhs_expr->id();
    or_ex->operands.push_back(lhs_expr);
    or_ex->operands.push_back(rhs_expr);
    
    return or_ex;
}



op* get_expression(IT &first, IT &last){
    if(first == last){
        return nullptr;
    }
    
    op* one_or_more_expr = make_more_exprs(first, last);
    if(!one_or_more_expr){
        one_or_more_expr = get_one_expr(first, last);
    }
    // single expression = expr
//    op* expr = get_one_expr(first, last);
//    if(!expr) return nullptr;
    op* ex = new expression;
    ex->operands.push_back(one_or_more_expr);
    return ex;
    
    
    
    
    /*
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
    
    return choice;*/
    
}

op* make_more_exprs(IT &first, IT &last){
    if(first == last){
        return nullptr;
    }
    
    op* more_expr = new expression;
    op* one_expr = get_one_expr(first, last);
    while(one_expr != nullptr){
        more_expr->operands.push_back(one_expr);
        one_expr = get_one_expr(first, last);
    }
    
    return more_expr;
}


op* get_one_expr(IT &first, IT &last){
    if(first == last){
        return nullptr;
    }
//    std::vector<std::function<op*(IT &first, IT &last)>> func_calls = {make_or_expr, get_string_expr};
    // string.
//    op* expr = get_string_expr(first, last);
//    if(!expr){
//        return nullptr;
//    }
    IT start = first;
    op* which_expr = make_or_expr(first, last);
    if(!which_expr){
        which_expr = get_string_expr(first, last);
    }
    
    
    /*
    op* expr;
    for(auto function: func_calls){
        expr = function(first, last);
        if(expr) break;
    }
    */
    if(!which_expr){
        first = start;
        return nullptr;
    }
    op* ex = new one_expr;
    ex->operands.push_back(which_expr);
    return ex;
}

op* get_string_expr(IT& first, IT& last)
{
    if(first == last) return nullptr;
    IT start = first;
    string_expr* str = new string_expr;
    token tk = next_token(first, last);

    while(tk.id == token::CHAR) 
    {
        str->_id += tk.text;
        tk = next_token(++first, last);
    }
    if(start == first) return nullptr;
    return str;
}

op* parser(IT &first, IT &last){
    
    if(first == last){
        return nullptr;
    }
    
    op* expr = get_expression(first, last);

    
    
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

void print_ast_tree(op*& o, int i)
{
    i++;
    for(int j = 0; j < i; j++) 
    { 
            std::cout<<" |"; 
    }
    std::cout<<o->id()<<std::endl; 
    for(auto e : o->operands) 
    {
        print_ast_tree(e, i);
    }
}
/*
 * 
 */
int main(int argc, char** argv) {

    
    // This can be ".*"
//    std::string in = "W(YOU+HELLO)THERE";
//    std::string input = "WATERLOO HELLO THERE";
    
//    std::string true_in = "promise to (love+hate)";
    std::string source = "Waterloo I was defeated, you won the war Waterloo promise to love you for ever more Waterloo couldn't escape if I wanted to Waterloo knowing my fate is to be with you Waterloo finally facing my Waterloo";
//    std::cout << *in.begin() << " " << *(in.end()-1) << "\n";
//    std::string tets = "promise to love you";
    
    std::string input = "yyyy + love";
//    std::string input = "defeated";
//    std::string input = "love + yyyyy";
    IT source_begin = source.begin();
    IT source_end = source.end();
    IT input_begin = input.begin();
    IT input_end = input.end();
    
    op* res = parser(input_begin, input_end);
    //std::cout << res->eval(input) << "\n";
    // This is Waterloo paragraf.
//    printTree(res);
    print_ast_tree(res, 0);
    
    if(res->eval(source_begin, source_end)){
        std::cout << matched << std::endl;
    }else{
        std::cout << matched << std::endl;
        std::exit(EXIT_FAILURE);
    }
    
    for (auto e : captures) {
        std::cout << e << std::endl;
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

