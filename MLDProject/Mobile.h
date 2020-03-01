#pragma once
#include "DigitalEquitment.h"
#include <string>
class Mobile :public DigitalEquitment
{
private :
	int size;
	string color;
	
	
public:
	
	Mobile(string code, string name, string brand, int number, string details, int price, int size, string color);
	~Mobile();
	
};

