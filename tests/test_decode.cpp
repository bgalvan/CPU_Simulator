// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include "Decode.h"

TEST_CASE("test decode constructor", "parts") {
	std::string name = "Decode";
	Decode dec(name);
	REQUIRE(dec.get_name() == name);

}

TEST_CASE("Test_decode", "parts") {
	
	std::string name = "Decode";

	uint16_t a = 61359;
	uint16_t b = 38314;
	Decode dec(name);
	dec.DecodeIns(a,b);
}
