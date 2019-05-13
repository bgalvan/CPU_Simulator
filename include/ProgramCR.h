//Copyright 2019 Shaun Peretz
#pragma once
#include <fstream>
#include <string>
#include "Component.h"

class ProgramCR : public Component {
        public:
		//constructor 
		explicit ProgramCR(std::string fn);

		
		//mutator 
		void tick(void);
	private:
		std::string fname;
		uint16_t val;
};
