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
#include "iostream"

struct characters : op {

    bool eval(std::string text) override {

//        std::cout << text << " ";

        
        extern std::string matched;

//        std::cout << matched << " ";
        
//        if(id() != text.substr(0, 1))
//            return false;
        
        if (!operands[0]){
            if(matched == ""){
                for(int i = 0; i < text.size(); i++){

                if(id() == text.substr(0, 1)){
                    matched = matched + id();
//                    std::cout << matched << " ";
                    // evaluate the rest of the characters
                        return true;
//                        matched = "";
//                        break;
                    // if some next character don't match, reset matched and continue.
                    }else
                        matched = "";
//                    break;
                }
                
//                std::cout << text << " ";

                // decrease text by one
                text = text.substr(1);
            
            }else if(id() != text.substr(0, 1))
                matched = "";
            
            if(id() == ")")
                return true;
            
            if(id() == text.substr(0, 1))
                matched = matched+id();


            return id() == text.substr(0, 1);
        }
//        
//        if(id() == text.substr(0, 1))
//            matched = matched+id();
//
//        if(id() == ")")
//            return operands[0]->eval(text.substr(1));


        // if nothing matched before
        if(matched == ""){
            
            // Look for starting character
            for(int i = 0; i < text.size();){

                if(id() == text.substr(0, 1)){
                    matched = matched + id();
//                    std::cout << matched << " ";
                    // evaluate the rest of the characters
                    if (operands[0]->eval(text.substr(1))){
                        return true;
//                        matched = "";
//                        break;
                    // if some next character don't match, reset matched and continue.
                    }else
                        matched = "";
//                    break;
                }
                
//                std::cout << text << " ";

                // decrease text by one
                text = text.substr(1);
            }
        }else if(id() == text.substr(0, 1))
            matched = matched+id();
         
        
        return id() == text.substr(0, 1) && operands[0]->eval(text.substr(1));
    }
    std::string id() override {
        return this->_id;
    }

    
    std::string _id;
//    characters* child;
};



#endif /* CHARACTER_H */

