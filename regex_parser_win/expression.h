
/* 
 * File:   expression.h
 * Author: André
 *
 * Created on den 18 februari 2020, 23:46
 */

#ifndef EXPRESSION_H
#define EXPRESSION_H
#include "op.h"

struct expression:op{
    bool eval(IT& begin, IT& end) override{
        for(auto e: operands){
            if(!e->eval(begin, end)){
                return false;
            }
        }
        return true;
    }
    
    std::string id() override{
        return "EXPRESSION";
    }

};

#endif /* EXPRESSION_H */

