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
       
        if (!child){
            extern std::string matched;
            matched = matched+text.substr(0, 1);
//            std::cout << "CHAR_CHILD: " << text.substr(0, 1) << "\n";
        

            return _id == text.substr(0, 1);
        }
        extern std::string matched;
        matched = matched+text.substr(0, 1);
//        std::cout << "CHAR: " << text.substr(0, 1) << "\n";

        return _id == text.substr(0, 1) && child->eval(text.substr(1));
    }
    std::string id() override {
        return this->_id;
    }

    std::string _id;
    characters* child;
};



#endif /* CHARACTER_H */

