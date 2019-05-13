#include "RegisterM.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
#include <sstream>

RegisterM::RegisterM(std::string n, int SIZE):Component(n) {
	this->add_in_pin("opcode");
	this->add_in_pin("opcode2");
	this->add_out_pin("output1");
	this->add_out_pin("output2");

	int size = SIZE;

	arrm = new uint8_t[size];
	uint8_t *arrm[size];

}

void RegisterM::tick(void) {
	Pin *inpin = this->get_in_pin("opcode");
	Pin *outpin = this->get_out_pin("output1");


	int ival, oval;

	if (inpin) {
		ival = inpin->get_val();
		oval = ival;
	}

	if (outpin) {
		outpin->set_val(oval);
	}
	
	Pin *outpin1 = this->get_out_pin("output1");
	Pin *outpin2 = this->get_out_pin("opcode2");

	//uint8_t opcode = this->arrm[ival];
	//uint8_t opcode2 = this->arrm[ival+1];

	//outpin1->set_val(opcode);
	//outpin2->set_val(opcode2);

}
