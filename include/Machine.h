// Copyright 2018 Roie R. Black
#pragma once
#include <string>

class Machine {
 public:
     // constructor
     explicit Machine(std::string n);

     // accessors
     std::string get_name(void);

     // mutators
     void run(void);

 private:
     std::string name;
     int num_parts;
     int num_wires;
};
