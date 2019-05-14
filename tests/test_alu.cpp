// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include <iostream>
#include "ALU.h"

TEST_CASE("test ALU constructor", "parts") {
	std::string NAME = "CPUtest";
       	ALU alu(NAME);
	REQUIRE(alu.get_name() == NAME);

}

TEST_CASE("Test_ALU", "parts") {
	std::string name = "ALU";
	
	ALU alu(name);

	Pin * inpin1 = alu.get_in_pin("ALUop");
	Pin * outpin1 = alu.get_out_pin("sum");
	Pin * inpin2 = alu.get_in_pin("opcode1");
	Pin * inpin3 = alu.get_in_pin("opcode2");
	std::cout << "\nTesting ALU: " << std::endl;

	//inpin1 0 = add, 1 = sub, 8 = and, 9 = eor, 10 = or, 74 = com
	inpin1->set_val(0); // ADD

	inpin2->set_val(1);
	inpin3->set_val(1);
	
	alu.tick();

	inpin1->set_val(10); // OR
	inpin2->set_val(2);
	inpin3->set_val(4);
	alu.tick();

	inpin1->set_val(74); // COM
	inpin2->set_val(2);
	
	alu.tick();

	//REQUIRE(outpin1->get_val() == 2 );
	
	
}
