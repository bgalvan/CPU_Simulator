//Copyright 2019 Shaun Peretz
#include "ProgramCR.h"
#include <iostream>
#include <fstream>
#include <string>


//constructor
ProgramCR::ProgramCR(std::string fn):Component(fn) {
	this->add_in_pin("IN");
	this->add_out_pin("OUT");

	val = 0;
}



void ProgramCR::tick(void) {
	Pin *inpin = this->get_in_pin("IN");
	Pin *outpin = this->get_out_pin("OUT");
	uint16_t ival, oval;

	oval = val;
	if (inpin) {
		val = inpin->get_val();
	}

	if (outpin) {
		outpin->set_val(oval);
	}
}

