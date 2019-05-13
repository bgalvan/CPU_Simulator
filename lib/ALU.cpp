#include "ALU.h"
#include <iostream>
#include <string>
#include <cstdint>
#include <bitset>
#include <sstream>

ALU::ALU(std::string n):Component(n) {
	this->add_in_pin("ALUop");
	this->add_in_pin("opcode1");
	this->add_in_pin("opcode2");
	this->add_out_pin("sum");
	this->add_out_pin("Z");

	std::string name = n;


}

void ALU::tick(void) {
	Pin *inpin1 = this->get_in_pin("ALUop");
	Pin *inpin2 = this->get_in_pin("opcode1");
	Pin *inpin3 = this->get_in_pin("opcode2");
	Pin *outpin1 = this->get_out_pin("sum");

	op = inpin1->get_val(); //operation
	Rd = inpin2->get_val(); //operand 1
	Rr = inpin3->get_val(); //operand 2

	switch (op) {
            case 0: //ADD 
		{
		int rd = (uint8_t) Rd;
		int rr = (uint8_t) Rr;
		int res = (uint8_t) sum;
			
		
                    std::cout << "ADD "
			<< rd
 			<< " + " 
                        << rr
			<< " Equals ";
		    res = rd + rr;
		    std::cout << res << std::endl;
		    outpin1->set_val(res);

                }
                break;
            case 1: // SUB
		{
		int rd = (uint8_t) Rd;
		int rr = (uint8_t) Rr;
		int res = (uint8_t) sum;
                    std::cout << "SUB "
                        << rd
                        << "-"  
                        << rr
			<< " Equals ";
		    res = rd - rr;
		    std::cout << res << std::endl;
		    outpin1->set_val(res);
                }
                break;
            case 8: //AND 
		{
		std::string rd = std::bitset<8>(Rd).to_string();
		std::string rr = std::bitset<8>(Rr).to_string();
		std::string sum = std::bitset<8>(Rd).to_string();
		
                    std::cout << "AND "
                        << rd
                        << " & "  
                        << rr
			<< " Equals ";
		    
		    for (int i=0; i<8; i++) {
			    if ((rd[i] == '1') && (rr[i] == '1')) {
				    sum[i] = '1';
			    }
			    else 
				    sum[i] = '0';
		    }
		    int res = std::stoi(sum);
		    std::cout << res << std::endl;
		    outpin1->set_val(res);         
		}       
		break;
            case 9: //EOR
		{
		std::string rd = std::bitset<8>(Rd).to_string();
		std::string rr = std::bitset<8>(Rr).to_string();
		std::string sum = std::bitset<8>(Rd).to_string();
		
                    std::cout << "EOR "
                        << rd
                        << " X "  
                        << rr
			<< " Equals ";
		    
		    for (int i=0; i<8; i++) {
			    if ((rd[i] == '1') && (rr[i] == '0')) 
				    sum[i] = '1';
			    else if ((rd[i] == '0') && (rr[i] == '1')) 
				    sum[i] = '1';
			    else 
				    sum[i] = '0';
		    }
		    int res = std::stoi(sum);
		    std::cout << res << std::endl;
		    outpin1->set_val(res);   
		}
                break;
	    case 10: //OR
		{
		std::string rd = std::bitset<8>(Rd).to_string();
		std::string rr = std::bitset<8>(Rr).to_string();
		std::string sum = std::bitset<8>(Rd).to_string();
		
                    std::cout << "OR "
                        << rd
                        << " X "  
                        << rr
			<< " Equals ";
		    
		    for (int i=0; i<8; i++) {
			    if ((rd[i] == '1') && (rr[i] == '0')) 
				    sum[i] = '1';
			    else if ((rd[i] == '0') && (rr[i] == '1')) 
				    sum[i] = '1';
			    else if ((rd[i] == '1') && (rr[i] == '1'))
				    sum[i] = '1';
			    else 
				    sum[i] = '0';
		    }
		    int res = std::stoi(sum);
		    std::cout << res << std::endl;
		    outpin1->set_val(res); 
		}
                break;
	    case 74: //COM
		{
		std::string rd = std::bitset<8>(Rd).to_string();
		std::string sum = std::bitset<8>(Rd).to_string();
		
                    std::cout << "COM "
                        << rd
                        << " X"  
			<< " Equals ";
		    
		    for (int i=0; i<8; i++) {
			    if (rd[i] == '1') 
				    sum[i] = '0';
			    else 
				    sum[i] = '1';
		    }
		    int res = std::stoi(sum);
		    std::cout << res << std::endl;
		    outpin1->set_val(res); 

		}
                break;
	    default: std::cout << "Instruction Invalid." << std::endl;
        }





	
	
}
