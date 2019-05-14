#pragma once
#include "Component.h"
#include <string>

class Store : public Component {

	private:
		int SIZE;
        int itemCount = 0;
        uint16_t *stack;
        uint16_t *data;
        uint16_t *ioMemory;

	public:
		//constructor
		explicit Store (std::string n, int SIZE);

		//mutator
		void tick(void);

		int get_size();
        bool isEmpty();
        void push(uint16_t n);
        void pop();
        uint16_t peek();

        uint8_t ioRead(int index);
        void ioWrite(uint8_t data, int index);
        uint16_t stackRead();
        void stackWrite(uint16_t data);
        uint8_t dataRead(int index);
        void dataWrite(uint8_t data, int index);
};


