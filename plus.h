/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   plus.h
 * Author: anden
 *
 * Created on March 11, 2019, 6:22 PM
 */

#ifndef PLUS_H
#define PLUS_H

#include "op.h"
#include "string"

struct plus:op{
    bool eval(std::string text) override {
        
    }

    std::string id() override {
        return this->_id;
    }

    std::string _id;
};

#endif /* PLUS_H */

