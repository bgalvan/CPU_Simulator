// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include "InstructionM.h"

TEST_CASE("test insturctionM constructor", "parts") {
	std::string NAME = "CPUtest";
	int SIZE;
	InstructionM IM(NAME, SIZE);
	REQUIRE(IM.get_name() == NAME);

}

TEST_CASE("Test_IM", "parts") {
	std::string file = "blink.hex";
	int SIZE = 50;
	std::string name = "IM";
	
	InstructionM IM(name, SIZE);

	IM.load(file);

	Pin * inpin = IM.get_in_pin("PCin");
	Pin * outpin = IM.get_out_pin("PCout");
	inpin->set_val(1);
	REQUIRE(inpin->get_val() == 1);
	IM.tick();
	//REQUIRE( outpin->get_val() == 1 );
	//inpin->set_val(0);
	//IM.tick();
	//REQUIRE( outpin->get_val() == 0);
	
	


	

	
}
