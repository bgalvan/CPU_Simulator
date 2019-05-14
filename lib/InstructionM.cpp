#include "InstructionM.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdlib>

InstructionM::InstructionM(std::string n, int SIZE):Component(n) {
	this->add_in_pin("PCin");
	this->add_out_pin("PCout");
	this->add_out_pin("opcode");
	this->add_out_pin("opcode2");

	
	int size = SIZE;
	fname = n;

	arr = new uint16_t[size];
	uint16_t *arr[size];

}

void InstructionM::tick(void) {
	Pin *inpin = this->get_in_pin("PCin");
	Pin *outpin = this->get_out_pin("PCout");


	uint16_t ival, oval;

	if (inpin) {
		ival = inpin->get_val();
		oval = ival;
	}

	if (outpin) {
		outpin->set_val(oval);
	}
	Pin *outpin1 = this->get_out_pin("opcode");
	Pin *outpin2 = this->get_out_pin("opcode2");

	uint16_t opcode = this->arr[ival];
	uint16_t opcode2 = this->arr[ival+1];


	outpin1->set_val(opcode);
	outpin2->set_val(opcode2);
	std::cout << "Data item at location #" << ival << ": " << opcode << std::endl;
	std::cout << "Data item at location #" << ival+1 << ": " << opcode2 << std::endl;


}

int InstructionM::parse(std::string n, int count) {
    int len = n.size();
    std::string d;

    // check record mark
    if (n[0] != ':') {
        std::cout << "bad data line" << std::endl;
	return 0;
    }

    // check record length
    std::string bytes = n.substr(1, 2);
    //std::cout << "Byte count: " << bytes << std::endl;

    // get load offset
    std::string offset = n.substr(3, 4);
    //std::cout << "Offset: " << offset << std::endl;

    // check record type
    std::string record = n.substr(7, 2);
    //std::cout << "Record Type: " << record << std::endl;

    // get data bytes
    std::string data = n.substr(9, len-11);
    //std::cout << "Record data: " << data << std::endl;

    

    // get checksum (not checked)
    std::string check = n.substr(len-2, 2);
    //std::cout << "Checksum: " << check << std::endl;

    int lendata = data.size();

 
    if (lendata == 32)
    {
	    std::string data1 = n.substr(9,2);
	    std::string data2 = n.substr(11,2);
	    std::string word1 = data2 + data1; //flip bytes and add #1
	    
	    std::stringstream s1;
	    s1 << std::hex << word1;
	   
	    uint16_t n1;
	    s1 >> n1;
	    std::bitset<16> b1(n1);
	    //std::cout << b1 << std::endl;

	    //unsigned short myshort = (unsigned short)b1.to_ulong();


	    std::string data3 = n.substr(13,2);
	    std::string data4 = n.substr(15,2);
	    std::string word2 = data4 + data3; //flip bytes and add #2

	    std::stringstream s2;
	    s2 << std::hex << word2;
	    uint16_t n2;
	    s2 >> n2;
	    std::bitset<16> b2(n2);

	    std::string data5 = n.substr(17,2);
	    std::string data6 = n.substr(19,2);
	    std::string word3 = data6 + data5; //flip bytes and add #3
	    
	    std::stringstream s3;
	    s3 << std::hex << word3;
	    uint16_t n3;
	    s3 >> n3;
	    std::bitset<16> b3(n3);
	    //std::cout << b3 << std::endl;

	    std::string data7 = n.substr(21,2);
	    std::string data8 = n.substr(23,2);
	    std::string word4 = data8 + data7; //flip bytes and add #4
	    
	    std::stringstream s4;
	    s4 << std::hex << word4;
	    uint16_t n4;
	    s4 >> n4;
	    std::bitset<16> b4(n4);

	    std::string data9 = n.substr(25,2);
	    std::string data10 = n.substr(27,2);
	    std::string word5 = data10 + data9; //flip bytes and add #5
	    
	    std::stringstream s5;
	    s5 << std::hex << word5;
	    uint16_t n5;
	    s5 >> n5;
	    std::bitset<16> b5(n5);

	    std::string data11 = n.substr(29,2);
	    std::string data12 = n.substr(31,2);
	    std::string word6 = data12 + data11; //flip bytes and add #6

	    std::stringstream s6;
	    s6 << std::hex << word6;
	    uint16_t n6;
	    s6 >> n6;
	    std::bitset<16> b6(n6);

	    std::string data13 = n.substr(33,2);
	    std::string data14 = n.substr(35,2);
	    std::string word7 = data14 + data13; //flip bytes and add #7
	    
	    std::stringstream s7;
	    s7 << std::hex << word7;
	    uint16_t n7;
	    s7 >> n7;
	    std::bitset<16> b7(n7);

	    std::string data15 = n.substr(37,2);
	    std::string data16 = n.substr(39,2);
	    std::string word8 = data16 + data15; //flip bytes and add #8
	    
	    std::stringstream s8;
	    s8 << std::hex << word8;
	    uint16_t n8;
	    s8 >> n8;
	    std::bitset<16> b8(n8);

	 
	    

	    arr[count] = n1;
	    count++;
	    arr[count] = n2;
	    count++; 
	    arr[count] = n3;
	    count++;
	    
	    arr[count] = n4;
	    count++;
	   
	    arr[count] = n5;
	    count++;
	    arr[count] = n6;
	    count++;
	    arr[count] = n7;
	    count++;
	    arr[count] = n8;
	    
	    


	    return count;

    }
    else if (lendata == 4) 
    {
	    std::string data1 = n.substr(9,2);
	    std::string data2 = n.substr(11,2);
	    std::string word1 = data2 + data1; //flip bytes and add
	    
	    std::stringstream s1;
	    s1 << std::hex << word1;
	    uint16_t n1;
	    s1 >> n1;
	    std::bitset<16> b1(n1);

	    arr[count] = n1;
	    

	    return count;

    }

    else
    {
	    return count;
    }


}

int InstructionM::get_size(void)
{
	return SIZE;
}

void InstructionM::load(std::string name) {	
    std::ifstream fin;
    std::string line;
   
    int count = 0;

    fin.open(name, std::ios::in);
    if (fin.is_open()) {
        fin >> line;
        while (!fin.eof()) {
            //std::cout << line << std::endl;
	    count = parse(line, count);
	    count++;
            fin >> line;
        }
	fin.close();
    } else {
        std::cout << "error reading file" << std::endl;
    }
    


 
    

}


