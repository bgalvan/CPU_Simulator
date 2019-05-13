#pragma once
#include "Component.h"
#include <iostream>
#include <string>

class RegisterM : public Component {
	private:
		uint8_t *arrm;
		int SIZE;
	
	public: 
		explicit RegisterM(std::string n,int SIZE);
		void tick(void);
};

