#include <catch.hpp>
#include "ProgramCR.h"

TEST_CASE("test programcr constructor", "parts") {
	std::string NAME = "CPUtest";
	ProgramCR prog(NAME);
	REQUIRE(prog.get_name() == NAME);
}

TEST_CASE("Test_programcr operation", "parts") {
	std::string name = "Prog";
	ProgramCR prog(name);
	Pin * inpin = prog.get_in_pin("IN");
	Pin * outpin = prog.get_out_pin("OUT");
	inpin->set_val(1);
	prog.tick();
	REQUIRE(outpin->get_val() == 0);
	inpin->set_val(0);
	prog.tick();
	REQUIRE(outpin->get_val() == 1);
}
