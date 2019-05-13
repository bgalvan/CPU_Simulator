// Copyright 2018 Roie R. Black
#include "Inverter.h"
#include <iostream>
#include <string>

// constructor
Inverter::Inverter(std::string n):Component(n) {
    this->add_in_pin("IN");
    this->add_out_pin("OUT");
}

// TICK: perform component processing
void Inverter::tick(void) {
    Pin *inpin = this->get_in_pin("IN");
    Pin *outpin = this->get_out_pin("OUT");
    uint16_t ival, oval;

    if (inpin) {
        ival = inpin->get_val();
        oval = ival == 0 ? 1 : 0;
    }
    if (outpin) {
        outpin->set_val(oval);
    } 
}

