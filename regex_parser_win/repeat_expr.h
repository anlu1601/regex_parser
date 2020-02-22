/*
 * File:   more_expr.h
 * Author: André
 *
 * Created on den 21 februari 2020, 00:15
 */

#ifndef REPEAT_EXPR_H
#define REPEAT_EXPR_H
#include "op.h"
extern IT begin_of_match;
struct repeat_expr: op {
    std::string _id;
    bool eval(IT &begin, IT &end) override{

        if (_id == ".") {
            begin_of_match = begin;
            begin  = end;
            return true;
        }else if(*begin == _id[0]){
            
            while(*begin == _id[0]){
                begin++;
            }
            return true;
        }
        return false;
    }
    
    std::string id() override{
        return "REPEAT-EXPR" + _id;
    }
};


#endif /* REPEAT_EXPR_H */

