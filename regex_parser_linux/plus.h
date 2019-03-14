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
        
        
//        extern std::string matched;
//        matched = matched+text.substr(0, 1);
        
        return operands[0]->eval(text) || operands[1]->eval(text);//?????
        
    }

    std::string id() override {
        return this->_id;
    }

//    characters* lhs;
//    characters* rhs;
    std::string _id;
};

#endif /* PLUS_H */

