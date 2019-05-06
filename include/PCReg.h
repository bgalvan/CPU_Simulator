// Copyright 2018 Roie R. Black
#pragma once
#include <string>
#include "Component.h"

class PCReg : public Component {
 public:
    // constructors
    explicit PCReg(std::string n);

    // mutators
    void tick(void);
};