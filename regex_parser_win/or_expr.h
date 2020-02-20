
/* 
 * File:   or_expr.h
 * Author: André
 *
 * Created on den 20 februari 2020, 00:01
 */

#ifndef OR_EXPR_H
#define OR_EXPR_H
#include "op.h"

extern std::vector<std::string> captures;

struct or_expr:op{
    
    std::string rhs;
    std::string lhs;
    
    bool eval(IT& begin, IT& end) override{
        
        auto left_input = std::string(begin, begin + lhs.size());
        auto right_input = std::string(begin, begin + rhs.size());
        
        if(left_input == lhs){
            captures.push_back(left_input);
            begin = begin + lhs.size();
            return true;
        }else if(right_input == rhs){
            captures.push_back(right_input);
            begin = begin + rhs.size();
            return true;
        }
        return false;
        
        
    }

    std::string id() override{
        return "OR";
    }
    
};


#endif /* OR_EXPR_H */

