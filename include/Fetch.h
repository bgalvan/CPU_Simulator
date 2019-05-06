// Copyright 2018 Roie R. Black
#pragma once
#include <string>
#include "Component.h"

class Fetch : public Component {
 public:
    //data
    uint16_t *data;
    int size;
    // constructors
    explicit Fetch(std::string n, int s);

    // mutators
    void tick(void);
    void load(std::string fn);
};