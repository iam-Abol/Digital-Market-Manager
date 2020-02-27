#include "stdafx.h"
#include "Mobile.h"
#include "DigitalEquitment.h"
#include <string>
using namespace std;
Mobile::Mobile()
{
}


Mobile::~Mobile()
{
}

Mobile::Mobile(string code1, string name1, string brand1, int number1, string details1, int price1,int size1,string color1)
{
	DigitalEquitment(code1, name1, brand1, number1, details1, price1);

	size = size1;
	color = color1;
	 
	
}