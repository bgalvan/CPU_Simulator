// Copyright 2018 Roie R. Black
#include <catch.hpp>
#include "Inverter.h"

TEST_CASE("test inverter constructor", "parts") {
    std::string NAME = "CPUtest";
    Inverter inv(NAME);
    REQUIRE(inv.get_name() == NAME);
}

TEST_CASE( "test_inverter operation", "parts" ) {
    std::string name = "INV";
    Inverter inv(name);
    Pin * inpin = inv.get_in_pin("IN");
    Pin * outpin = inv.get_out_pin("OUT");
    inpin->set_val(1);
    inv.tick();
    REQUIRE( outpin->get_val() == 0 );
    inpin->set_val(0);
    inv.tick();
    REQUIRE( outpin->get_val() == 1 );
}

