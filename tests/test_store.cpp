// Copyright 2018 ROie R. Black
#include <catch.hpp>
#include <iostream>
#include "Store.h"

TEST_CASE("test store constructor", "parts") {
	std::string NAME = "Storetest";
	int SIZE;
	Store store(NAME, SIZE);
	REQUIRE(store.get_name() == NAME);

}

TEST_CASE("Test_Store", "parts") {
	int SIZE = 50;
	std::string name = "Store";
	
	Store store(name, SIZE);

	std::cout << "\nTesting Store:" << std::endl;

    uint8_t ioMemoryItem = 128;

    uint8_t dataItem = 255;

    uint16_t stackItem = 1000;

    std::cout << "\nTesting I/O Memory:" << std::endl
    << "Writing item to ioMem @ index 10..." << std::endl;
    store.ioWrite(ioMemoryItem, 10);
    std::cout << "Reading item at index 10:" << std::endl
    << +store.ioRead(10) << std::endl;
    REQUIRE( store.ioRead(10) == 128 );

    std::cout << "\nTesting Data Memory:" << std::endl
    << "Writing item to dataMem @ index 5..." << std::endl;
    store.dataWrite(dataItem, 5);
    std::cout << "Reading item at index 5:" << std::endl
    << +store.dataRead(5) << std::endl;
    REQUIRE( store.dataRead(5) == 255 );

    std::cout << "\nTesting Stack:" << std::endl
    << "Pushing item to stack..." << std::endl;
    store.stackWrite(stackItem);
    std::cout << "Peeking at stack:" << std::endl
    << store.stackRead() << std::endl;
    REQUIRE( store.stackRead() == 1000 );



	

	
}
