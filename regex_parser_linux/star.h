/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   star.h
 * Author: anden
 *
 * Created on March 15, 2019, 6:28 PM
 */

#ifndef STAR_H
#define STAR_H

#include "characters.h"
#include <iostream>


struct star:characters {
    bool eval(std::string text) {
        
        extern std::string matched;
        matched = matched+text.substr(0, 1);
        
        int counter = 1;
        while(id() == text.substr(0, 1)){
            return operands[1]->eval(text.substr(counter));
            counter++;
        }
        
        return operands[0]->eval(text.substr(counter));
    }

    std::string id() {
        return this->_id;
    }

    std::string _id;
};

#endif /* STAR_H */

