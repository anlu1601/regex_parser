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
        
        std::string dot = get_ch();
//        std::cout << dot << " ";
//        if(get_ch() == ".")
//            set_ch(text.substr(0, 1));
//        
//        if(get_ch() != text.substr(0, 1))
//            return false;
        
        std::string ch = text.substr(0, 1);
        std::string star = text.substr(0, 1);
        
        if(dot != "."){
            while(ch == star){
                matched = matched + ch;

                text = text.substr(1);
                star = text.substr(0 ,1);
            }
        }else{
            while(0 < text.size()){
                matched = matched + text.substr(0, 1);
                text = text.substr(1);
            }
        }
//        int counter = 0;
//        while(get_ch() == text.substr(0, 1) && get_ch() != ""){
//            
//            matched = matched+text.substr(0, 1);
//            counter++;
//            text = text.substr(1);
//            if(dot == ".")
//                set_ch(text.substr(0, 1));
//        }
        
        if(!operands[0]){    
            return true;
        }
        
        return operands[0]->eval(text);
    }

    std::string id() {
        return this->_id;
    }
    
    std::string get_ch(){
        return this->_ch;
    }
    
    void set_ch(std::string ch){
        _ch = ch;
    }
    
    std::string _ch;
    std::string _id;
};

#endif /* STAR_H */

