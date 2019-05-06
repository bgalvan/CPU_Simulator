// Copyright 2018 Roie R. Black
#include "Fetch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 


// constructor
Fetch::Fetch(std::string n, int s):Component(n) {
    this->add_in_pin("PCin");
    this->add_out_pin("PCout");
    this->add_out_pin("opcode");
    this->add_out_pin("opcode2");
    data = new uint16_t[s];
    // uint16_t *arr[s] = {};

}

// TICK: perform component processing
void Fetch::tick(void) {
    Pin *inpin = this->get_in_pin("PCin");
    Pin *outpin = this->get_out_pin("PCout");

    uint16_t ival, oval;
    ival = inpin->get_val();
    oval = ival;
    outpin->set_val(oval);

    Pin *opcodePin = this->get_out_pin("opcode");
    Pin *opcode2Pin = this->get_out_pin("opcode2");

    uint16_t opcode = this->data[ival];
    uint16_t opcode2 = this->data[ival + 1];

    opcodePin->set_val(opcode);
    opcode2Pin->set_val(opcode2);
};

// void Fetch::load(void){
//     std::ifstream inFile;
//     inFile.open("/Users/Bobby/localhost/school/2325/labs/lab2-cpu-factory-bgalvan/data.txt");
//     std::string line;
//     int sum = 0;
//     while (getline(inFile, line)) {
//         std::cout << line;
//         std::stringstream item(line);
//         // this->data[sum] = item;
//         sum = sum + 1;
//     }
//     inFile.close();
// }

void Fetch::load(std::string fn) {
    std::string line;
    std::fstream fin;

    // open file and parse lines
    fin.open(fn, std::ios::in);
    if (fin.is_open()) {
        while (!fin.eof()) {
            fin >> line;
            int len = line.size();

            std::cout << line << std::endl;

            for(int n = 1; n < len; n = n + 2){
                std::string bytes = line.substr(n, 2);
                std::cout << bytes << std::endl;
            }


            // std::string bytes = line.substr(1, 2);
            // std::cout << "Byte count: " << bytes << std::endl;

            // std::string offset = line.substr(3, 4);
            // std::cout << "Offset: " << offset << std::endl;

            // std::string record = line.substr(7, 2);
            // std::cout << "Record Type: " << record << std::endl;

            // std::string data = line.substr(9, len - 11);
            // std::cout << "Record data: " << data << std::endl;

            // std::string check = line.substr(len - 2, 2);
            // std::cout << "Checksum: " << check << std::endl;
        }
    }
}
