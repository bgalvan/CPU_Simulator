#pragma once
#include "Component.h"
#include <bitset>
#include <iostream>

class Decode : public Component {
	public:
		explicit Decode(std::string n);
		int getRd(std::bitset<4> b1, std::bitset<4>b2);
		int getRr(std::bitset<4>b1, std::bitset<4>b2);
		int getK(std::bitset<4>b1, std::bitset<4>b2);
		void DecodeIns(uint16_t a, uint16_t b);


	private:
};
		



