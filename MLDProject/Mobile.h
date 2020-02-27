#pragma once
#include "DigitalEquitment.h"
#include <string>
class Mobile :public DigitalEquitment
{
private :
	int size;
	string color;
public:
	Mobile();
	Mobile::Mobile(string code1, string name1, string brand1, int number1, string details1, int price1, int size1, string color1);
	~Mobile();
};

