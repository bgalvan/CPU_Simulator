// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include "RegisterM.h"

TEST_CASE("test RegisterM constructor", "parts") {
	std::string NAME = "CPUtest";
	int SIZE;
	RegisterM RM(NAME, SIZE);
	REQUIRE(RM.get_name() == NAME);

}

TEST_CASE("Test_RM", "parts") {

	int SIZE = 31;
	std::string name = "RM";
	
	RegisterM RM(name, SIZE);

	Pin * inpin = RM.get_in_pin("opcode");
	Pin * outpin = RM.get_out_pin("output1");
	inpin->set_val(1);
	REQUIRE(inpin->get_val() == 1);
	RM.tick();
}
