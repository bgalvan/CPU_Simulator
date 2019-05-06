// Copyright 2018 Roie R. Black
#include <catch.hpp>
#include "Fetch.h"

// TEST_CASE("test fetch constructor", "parts") {
//     std::string NAME = "CPUtest";
//     Inverter inv(NAME);
//     REQUIRE(inv.get_name() == NAME);
// }

TEST_CASE( "test_fetch operation", "parts" ) {
    std::string name = "FETCH";
    Fetch fetch(name, 1);
    Pin * inpin = fetch.get_in_pin("PCin");
    Pin * outpin = fetch.get_out_pin("PCout");
    inpin->set_val(1);
    fetch.tick();
    REQUIRE( outpin->get_val() == 1 );
    // inpin->set_val(0);
    // fetch.tick();
    // REQUIRE( outpin->get_val() == 1 );
    // uint16_t item = 0101010101010101;
    fetch.load("blink.hex");
    // REQUIRE( fetch.data[1] == item );
}