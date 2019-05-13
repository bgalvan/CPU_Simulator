// Copyright 2018 Roie R. Black
#include <iostream>
#include "Machine.h"
#include "Inverter.h"
#include "Wire.h"

Inverter inv1("INV1"), inv2("INV2"), inv3("INV3");
Wire w1("W1"), w2("W2"), w3("W3");

// constructor
Machine::Machine(std::string n) {
    name = n;
    num_parts = 3;
    num_wires = 3;

    w1.attach_driven(inv1.get_out_pin("OUT"));
    w1.attach_drives(inv2.get_in_pin("IN"));
    w2.attach_driven(inv2.get_out_pin("OUT"));
    w2.attach_drives(inv3.get_in_pin("IN"));
    w3.attach_driven(inv3.get_out_pin("OUT"));
    w3.attach_drives(inv1.get_in_pin("IN"));
}

// accessors
std::string Machine::get_name(void) {
    return name;
}

// mutators
void Machine::run(void) {
    inv1.get_in_pin("IN")->set_val(1);
    for (int i=0; i < 5; i++) {
        std::cout << "t" << i << ": ";
        // let all the components do something
        inv1.tick();
        inv2.tick();
        inv3.tick();
        // let all the wires do something
        w1.tock();
        std::cout
           << w3.get_driven_part_name()
           << "."
           << w3.get_driven_name()
           << " -("
           << w3.get_val()
           << ")-> "
           << w3.get_drives_part_name(0)
           << "."
           << w3.get_drives_names()
           << std::endl;
        w2.tock();
        w3.tock();
    }
}
