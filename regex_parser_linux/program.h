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
#include <iostream>

struct program:op {
    bool eval(std::string text){
        
        
//        std::size_t found = 0;
////        
////        std::cout << operands[0]->id() << "\n";
////        
////        
////        
//        if(child_Id() != "." && child_Id() != "+" && child_Id() != "("){
//            found = text.find(child_Id());
//            if(found != std::string::npos){
//                return operands[0]->eval(text.substr(found));
//
//            }
//            else{
//                return operands[0]->eval(text);
//        
//            }
//        }else{
//            return operands[0]->eval(text);
//        }

        return operands[0]->eval(text);
            
    }
    std::string id() override{
        return "program";
    }
    
    std::string child_Id() {
         return operands[0]->id();
    }

};

#endif /* PROGRAM_H */

