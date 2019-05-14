// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include <iostream>
#include "Decode.h"

TEST_CASE("test decode constructor", "parts") {
	std::string name = "Decode";
	Decode dec(name);
	REQUIRE(dec.get_name() == name);

}

TEST_CASE("Test_decode", "parts") {
	
	std::string name = "Decode";
	std::cout << "\nTesting Decode: " << std::endl;

	uint16_t a = 3437; //check ADD
	uint16_t b = 38314; //check hex file example LDI
	Decode dec(name);
	dec.DecodeIns(a,b);

	a = 6839; //check SUB
	b = 9053; //check AND
	dec.DecodeIns(a,b);

	a = 10995; //check OR
	b = 9980; //check EOR
	dec.DecodeIns(a,b);



	
}
