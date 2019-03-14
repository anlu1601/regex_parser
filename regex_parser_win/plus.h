/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   plus.h
 * Author: anden
 *
 * Created on March 11, 2019, 6:22 PM
 */

#ifndef PLUS_H
#define PLUS_H

#include "op.h"
#include "characters.h"
#include "string"


struct plus:op{
    bool eval(std::string text) override {
        std::size_t found_lhs;
        std::size_t found_rhs;
        
        
        if(child_lhs_Id() != "." && child_lhs_Id() != "+"){
            found_lhs = text.find(child_lhs_Id());
            if(found_lhs != std::string::npos){}
                
            else
                found_lhs = 0;
        }else{
            found_lhs = 0;
        }
        
        if(child_rhs_Id() != "." && child_rhs_Id() != "+"){
            found_rhs = text.find(child_rhs_Id());
            if(found_rhs != std::string::npos){}
                
            else
                found_rhs = 0;
        }else{
            found_rhs = 0;
        }
        
        
        return operands[0]->eval(text.substr(found_lhs)) || operands[1]->eval(text.substr(found_rhs));//?????
        
    }
    
    std::string child_lhs_Id() {
        return operands[0]->id();
    }
    
    std::string child_rhs_Id() {
        return operands[1]->id();
    }

    std::string id() override {
        return this->_id;
    }

//    characters* lhs;
//    characters* rhs;
    std::string _id;
};

#endif /* PLUS_H */

