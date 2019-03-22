/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   character.h
 * Author: anden
 *
 * Created on February 28, 2019, 3:35 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include "op.h"

struct characters : op {

    bool eval(std::string text) override {

        extern std::string matched;

        if (!operands[0]){
            
            if(id() == ")")
                return true;
            
            if(id() == text.substr(0, 1))
                matched = matched+id();


            return id() == text.substr(0, 1);
        }
        
        if(id() == text.substr(0, 1))
            matched = matched+id();

        if(id() == ")")
            return operands[0]->eval(text.substr(1));
        
        
        return id() == text.substr(0, 1) && operands[0]->eval(text.substr(1));
    }
    std::string id() override {
        return this->_id;
    }

    
    std::string _id;
//    characters* child;
};



#endif /* CHARACTER_H */

