#pragma once
#include "Component.h"
#include <bitset>
#include <iostream>

class ALU : public Component {
	public:
		explicit ALU(std::string n);
		void tick(void);
		
		

	private:
		uint8_t Rd;
		uint8_t Rr;
		int Z;
		uint8_t sum;
		int op;



};
