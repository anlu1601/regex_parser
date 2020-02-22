
/* 
 * File:   string_expr.h
 * Author: André
 *
 * Created on den 19 februari 2020, 00:54
 */

#ifndef STRING_EXPR_H
#define STRING_EXPR_H
#include "op.h"

extern std::vector<std::string> captures;
extern IT begin_of_match;

struct string_expr:op{
    std::string _id;
    
    bool eval(IT& begin, IT& end) override{
        auto input = std::string(begin, begin + _id.size());
            if(input == _id){
                captures.push_back(input);
                begin = begin + _id.size();
                return true;
            }
        
            /*// uncomment if not working
            auto a = end; 
            if (begin == end) {
                while(begin == end){
                input = std::string(a -_id.size(), a);
                if(input == _id){
                captures.push_back(std::string(begin_of_match, a));
                captures.push_back(input);
                begin = a;
                return true;
                }
                a--;
                }
            }*/
            
            
           
            return false;
    }
    
    
    std::string id() override{
        return _id;
    }
    int size() {
        return _id.size();
    }

};


#endif /* STRING_EXPR_H */

