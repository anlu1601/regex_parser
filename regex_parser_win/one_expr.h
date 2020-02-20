
/* 
 * File:   one_expr.h
 * Author: André
 *
 * Created on den 19 februari 2020, 01:15
 */

#ifndef ONE_EXPR_H
#define ONE_EXPR_H
#include "op.h"


struct one_expr: op {
    bool eval(IT &begin, IT &end) override{

        if(!operands[0]->eval(begin,end)){
                 return false;
        }
        return true;
    }
    std::string id() override{
        return "ONE_EXPR";
    }
};


#endif /* ONE_EXPR_H */

