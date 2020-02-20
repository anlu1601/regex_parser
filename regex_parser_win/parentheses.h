/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   parentheses.h
 * Author: anden
 *
 * Created on March 16, 2019, 11:26 PM
 */

#ifndef PARENTHESES_H
#define PARENTHESES_H

#include "op.h"
#include "characters.h"
#include "string"


struct parentheses:op{
    bool eval(std::string text) override {
                
        
//        std::cout << operands[0]->id() << "n\";
//        std::cout << operands[1]->id() << "n\";
//        
//        if((auto t = operands[0]) && (auto tt = operands[1]))
//            return operands[0]->eval(text) && operands[1]->eval(text);
//        else if(auto ttt = operands[0])
//            return operands[0]->eval(text);
//        else
//            return operands[1]->eval(text);
//                                                
//        
        return operands[0]->eval(text) && operands[1]->eval(text) && operands[2]->eval(text);

    }

    std::string id() override {
        return this->_id;
    }

    std::string _id;
};


#endif /* PARENTHESES_H */

