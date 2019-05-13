// Copyright 2018 Roie R. Black
#include "Component.h"
#include "Pin.h"

// constructors
Component::Component(std::string n) {
    name = n;
}

// accessor methods

std::string Component::get_name(void) {
    return name;
}

Pin * Component::get_in_pin(std::string name) {
    for (int i = 0; i < in_pins.size(); i++) {
        if (in_pins[i]->get_name() == name) return in_pins[i];
    }
    return nullptr;
}

Pin * Component::get_out_pin(std::string name) {
    for (int i = 0; i < out_pins.size(); i++) {
        if (out_pins[i]->get_name() == name) return out_pins[i];
    }
    return nullptr;
}

// mutator methods
void Component::add_in_pin(std::string name) {
    Pin * paddr = new Pin(name);
    paddr->set_val(42);
    paddr->set_part_addr(this);
    in_pins.push_back(paddr);
}

void Component::add_out_pin(std::string name) {
    Pin * paddr = new Pin(name);
    paddr->set_val(42);
    paddr->set_part_addr(this);
    out_pins.push_back(paddr);
}
