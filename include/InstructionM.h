#pragma once
#include "Component.h"
#include <string>

class InstructionM : public Component {

	private:
		std::string fname;
		uint16_t *arr;
		int SIZE;
		int parse(std::string n, int count);

	public:
		//constructor
		explicit InstructionM (std::string n, int SIZE);

		//mutator
		void tick(void);
		void load(std::string name);

		int get_size();
		

};



