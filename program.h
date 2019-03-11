/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   program.h
 * Author: anden
 *
 * Created on February 28, 2019, 1:50 PM
 */

#ifndef PROGRAM_H
#define PROGRAM_H

#include "op.h"


struct program:op {
    bool eval(std::string text){
        std::size_t found;
        
        if(id() != "."){
            found = text.find(id());
        }else{
            found = 0;
        }
        
        
                
        return operands[0]->eval(text.substr(found));
    }
    std::string id() override{
        return operands[0]->id();
    }

};

#endif /* PROGRAM_H */

