/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dot.h
 * Author: anden
 *
 * Created on March 7, 2019, 4:11 PM
 */

#ifndef DOT_H
#define DOT_H

#include "characters.h"


struct dot:characters {
    bool eval(std::string text) {
        
        
        if(!child){
            extern std::string matched;
            matched = matched+text.substr(0, 1);
//            std::cout << "DOT: " << text.substr(0, 1) << "\n";
            return true;
        }
        
        extern std::string matched;
        matched = matched+text.substr(0, 1);
//        std::cout << "DOT: " << text.substr(0, 1) << "\n";
        
        return child->eval(text.substr(1));
    }

    std::string id() {
        return this->_id;
    }

    std::string _id;
};

#endif /* DOT_H */

