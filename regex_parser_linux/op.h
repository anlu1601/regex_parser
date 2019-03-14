/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   op.h
 * Author: anden
 *
 * Created on February 19, 2019, 2:48 PM
 */

#ifndef OP_H
#define OP_H

#include <string>
#include <vector>

struct op {
    virtual bool eval(std::string text) = 0;
    virtual std::string id() = 0;
    std::vector<op*> operands;
};

#endif /* OP_H */

