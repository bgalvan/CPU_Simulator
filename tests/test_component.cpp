// Copyright 2018 Roie R. Black
#include <catch.hpp>
#include "Component.h"
#include "Pin.h"

TEST_CASE( "test component constructor", "component" ){
    const std::string name = "basic";
    Component part(name);
    REQUIRE(part.get_name() == name);
}

TEST_CASE( "test component pin attachment", "component" ) {
    const std::string pname = "PIN1";
    const std::string cname = "comp1";
    Component part(cname);
    Pin pin(pname);
    part.add_in_pin(pname);
    REQUIRE( part.get_in_pin(pname)->get_val() == 42 );
    part.add_out_pin(pname);
    REQUIRE( part.get_out_pin(pname)->get_val() == 42 );
}
