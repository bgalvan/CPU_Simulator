// Copyright 2018 Roie R. Black
#include "PCReg.h"
#include <iostream>
#include <string>

// constructor
PCReg::PCReg(std::string n):Component(n) {
    this->add_in_pin("IN");
    this->add_out_pin("OUT");
}

// TICK: perform component processing
void PCReg::PCReg::tick(void) {
    Pin *inpin = this->get_in_pin("IN");
    Pin *outpin = this->get_out_pin("OUT");
    uint16_t ival, oval;

    ival = inpin->get_val();
    oval = ival;
    outpin->set_val(oval);

}
