/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   chooser.h
 * Author: anden
 *
 * Created on March 17, 2019, 12:23 AM
 */

#ifndef CHOOSER_H
#define CHOOSER_H

#include "op.h"
#include "program.h"
#include <iostream>

struct chooser:op{
    bool eval(std::string text){
        
        
        std::size_t found = 0;
//        
        std::cout << operands[0]->id() << "\n";
//        std::cout << operands[0]->operands[0]->id() << "\n";
//        
//        
        op* c = operands[0];
        std::string ch_Id = c->id();
        
        while(true){
            if(ch_Id != "." && ch_Id != "+" && ch_Id != "(" && ch_Id != " "){
                found = text.find(ch_Id);
                if(found != std::string::npos){
                    return operands[0]->eval(text.substr(found));

                }
                else{
                    return operands[0]->eval(text);

                }
            }else{
                c->operands[0];
//                return operands[0]->eval(text);
            }
        }

            
    }
    std::string id() override{
        return "expression";
    }
    
    std::string child_Id() {
         return operands[0]->id();
    }
    
    

};

#endif /* CHOOSER_H */

