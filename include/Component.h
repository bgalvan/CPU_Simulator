// Copyright 2018 Roie R. Black
#pragma once

#include <string>
#include <vector>

#include "Component.h"
#include "Pin.h"


class Component {
 public:
    // constructor
    explicit Component(std::string n);

    // mutators
    void add_in_pin(std::string name);
    void add_out_pin(std::string name);
    void tick(void);

    // accessors
    std::string get_name(void);
    Pin * get_in_pin(std::string n);
    Pin * get_out_pin(std::string n);

 private:
    std::string name;
    std::vector<Pin *> in_pins;
    std::vector<Pin *> out_pins;
};


