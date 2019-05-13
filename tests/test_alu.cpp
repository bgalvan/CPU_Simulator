// Copyright 2018 ROie R. Black
#include <catch.hpp>
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

	//inpin1 0 = add, 1 = sub, 8 = and, 9 = eor, 10 = or, 74 = com
	inpin1->set_val(0);

	inpin2->set_val(1);
	inpin3->set_val(1);
	
	alu.tick();
	//REQUIRE(outpin1->get_val() == 2 );
	
	
}
