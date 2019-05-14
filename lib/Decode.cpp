// Test Decoding Logic
#include "Decode.h"
#include <iostream>
#include <string>
#include <cstdint>
#include<bitset>

Decode::Decode(std::string n):Component(n) {
	this->add_in_pin("opcode");
	this->add_in_pin("opcode2");
	this->add_out_pin("ALUop");
	this->add_out_pin("opcode");
	this->add_out_pin("opcode2");

	std::string name = n;
}


int Decode::getRd(std::bitset<4>b1, std::bitset<4>b2) {
    std::bitset<5> Rd;
    Rd[4] = b1[0]; 
    Rd[3] = b2[3];    
    Rd[2] = b2[2];    
    Rd[1] = b2[1];    
    Rd[0] = b2[0];

    return Rd.to_ulong();
    
}   

int Decode::getRr(std::bitset<4>b1, std::bitset<4>b2) {
    std::bitset<5>Rr;
    Rr[4] = b1[1];    
    Rr[3] = b2[3];    
    Rr[2] = b2[2];    
    Rr[1] = b2[1];    
    Rr[0] = b2[0];
    return Rr.to_ulong();
}

int Decode::getK(std::bitset<4>b1, std::bitset<4>b2) { //0 < K < 255
    std::bitset<8>K;
    K[7] = b1[3];    
    K[6] = b1[2];    
    K[5] = b1[1];    
    K[4] = b1[0];    
    K[3] = b2[3];
    K[2] = b2[2];    
    K[1] = b2[1];    
    K[0] = b2[0]; 

    return K.to_ulong();
}

void Decode::DecodeIns(uint16_t a, uint16_t b) {

	std::string a1 = std::bitset<16>(a).to_string();
	std::string b1 = std::bitset<16>(b).to_string();
	std::cout << "Instruction: " << a1 << std::endl;
	std::cout << "Instruction: " << b1 << std::endl;

	std::string dataA1 = a1.substr(0,4);
	std::string dataA2 = a1.substr(4,4);
	std::string dataA3 = a1.substr(8,4);
	std::string dataA4 = a1.substr(12,4);
	std::string dataB1 = b1.substr(0,4);
	std::string dataB2 = b1.substr(4,4);
	std::string dataB3 = b1.substr(8,4);
	std::string dataB4 = b1.substr(12,4);


	std::string code[2][4] = {};

	for (int i =0;i<1;i++) {
		code[i][0] = dataA1;
		code[i][1] = dataA2;
		code[i][2] = dataA3;
		code[i][3] = dataA4;
		code[i+1][0] = dataB1;
		code[i+1][1] = dataB2;
		code[i+1][2] = dataB3;
		code[i+1][3] = dataB4;

	}

	for(int i=0; i<2; i++) {
        std::bitset<4> b1((std::string(code[i][0])));
        std::bitset<4> b2((std::string(code[i][1])));
        std::bitset<4> b3((std::string(code[i][2])));
        std::bitset<4> b4((std::string(code[i][3])));


        switch (b1.to_ulong()) {
            case 0b0000: //ADD
                if (b2.test(3) && b2.test(2)) {
			int rd = getRd(b2,b3);
			int rr = getRr(b2,b4);
                    std::cout << "ADD "
                        << "R" 
                        << rd
                        << "," 
                        << "R"
                        << rr 
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
			Pin *outpin3 = this->get_out_pin("ALUop");

			int op = 0;
			uint8_t opcode = rd;
			uint8_t opcode2 = rr;

			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);
			outpin3->set_val(op);

                }
		else
			std::cout << "Instruction " << b1 << b2 <<  b3 <<  b4 << " is invalid." << std::endl;
                break;
            case 0b0001: //SUB
                if (b2.test(3) && !b2.test(2)) {
			int rd = getRd(b2,b3);
			int rr = getRr(b2,b4);
                    std::cout << "SUB "
                        << "R" 
                        << rr
                        << "," 
                        << "R" 
                        << rr
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
			Pin *outpin3 = this->get_out_pin("ALUop");

			int op = 1;
			uint8_t opcode = rd;
			uint8_t opcode2 = rr;

			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);
			outpin3->set_val(op);

                }
                break;
            case 0b0010: //AND OR EOR
		 if (!b2.test(3) && !b2.test(2)) {
			 int rd = getRd(b2,b3);
			 int rr = getRr(b2,b4);
                    std::cout << "AND "
                        << "R" 
                        << rd 
                        << "," 
                        << "R" 
                        << rr
                        << std::endl;
		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
			Pin *outpin3 = this->get_out_pin("ALUop");

			int op = 8;
			uint8_t opcode = rd;
			uint8_t opcode2 = rr;

			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);
			outpin3->set_val(op);


                }
		 else if (b2.test(3) && !b2.test(2)) { //OR
			 int rd = getRd(b2,b3);
			 int rr = getRr(b2,b4);
                    std::cout << "OR "
                        << "R" 
                        << rd
                        << "," 
                        << "R" 
                        << rr
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
			Pin *outpin3 = this->get_out_pin("ALUop");

			int op = 10;
			uint8_t opcode = rd;
			uint8_t opcode2 = rr;

			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);
			outpin3->set_val(op);

                }
		 else  { //EOR
			 int rd = getRd(b2,b3);
		 	 int rr = getRr(b2,b4);
                    std::cout << "EOR "
                        << "R" 
                        << rd 
                        << "," 
                        << "R" 
                        << rr
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
			Pin *outpin3 = this->get_out_pin("ALUop");

			int op = 9;
			uint8_t opcode = rd;
			uint8_t opcode2 = rr;

			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);
			outpin3->set_val(op);

                }
                break;
            case 0b1001: //COM
                if (!b4.test(1) && !b4.test(3)) {
			int rd = getRd(b2,b3);
                    std::cout << "COM "
                        << "R" 
                        << rd
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin3 = this->get_out_pin("ALUop");

			uint8_t opcode = rd;
			int op = 74;

			outpin1->set_val(opcode);
			outpin3->set_val(op);

		}
		else if (b4.test(1) && b4.test(3)) //DEC
		{
			int rd = getRd(b2,b3);
			std::cout << "DEC "
				<< "R"
				<< rd
				<< std::endl;

			Pin *outpin1 = this->get_out_pin("opcode");

			uint8_t opcode = rd;

			outpin1->set_val(opcode);

		}
                break;
		 
	    case 0b1110: //LDI 
		{
			int rd = getRd(b2,b3);
			int k = getRr(b2,b4);
                    std::cout << "LDI "
                        << "R" 
                        << rd 
                        << "," 
                        << "R" 
                        << k 
                        << std::endl;

		    	Pin *outpin1 = this->get_out_pin("opcode");
			Pin *outpin2 = this->get_out_pin("opcode2");
	
			uint8_t opcode = rd;
			uint8_t opcode2 = k;
	
			outpin1->set_val(opcode);
			outpin2->set_val(opcode2);

		}
                break;
		

        }

	
    }
}

