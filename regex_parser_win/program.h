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

#include <iostream>
#include <string>

#include "op.h"

struct program:op {
    std::string _id;
    
    bool eval(IT& begin, IT& end)override{
        
        while(begin != end){
            auto current_begin = begin;
            if(operands[0]->eval(current_begin, end)){
                if(operands[0]->id() == "OUT"){
                    std::cout << "OUT in program" << std::endl;
                }else if(operands[0]->id() == "EXPRESSION"){
                    std::cout << std::string(begin, current_begin) << std::endl;
                }
                return true;
            }
            begin++;
        }
        std::cout << "false" << std::endl;
        return false;
        
        
    }
    std::string id() override{
        return "program";
    }
    
    

};

#endif /* PROGRAM_H */

