#include "Store.h"
#include <iostream>

Store::Store(std::string n, int SIZE):Component(n) {
	int size = SIZE;
	stack = new uint16_t[size];
	uint16_t *stack[size];
    data = new uint16_t[size];
    uint16_t *data[size];
    ioMemory = new uint16_t[size];
    uint16_t *ioMemory[size];
    

}

//checks if empty
bool Store::isEmpty(){
    if (itemCount == 0)
    return true;
    else return false;
}

//pushes new item to top of stack
void Store::push(uint16_t newItem){
    stack[itemCount] = newItem;
    itemCount++;
}

//removes items from top of stack
void Store::pop(){
    if (isEmpty())
        std::cout << "Stack is empty\n";
    else
    {
        stack[itemCount] = 0;
        itemCount--;
        std::cout << "Top item removed.";
    }
}

//prints item at top of stack
uint16_t Store::peek(){
    return stack[itemCount-1];
}

uint16_t Store::stackRead(){
    return this->peek();
}

void Store::stackWrite(uint16_t data){
    this->push(data);
}

uint8_t Store::ioRead(int index){
     return this->ioMemory[index];
}

void Store::ioWrite(uint8_t data, int index){
    this->ioMemory[index] = data;
}

uint8_t Store::dataRead(int index){
    return this->data[index];
}

void Store::dataWrite(uint8_t data, int index){
    this->data[index] = data;
}