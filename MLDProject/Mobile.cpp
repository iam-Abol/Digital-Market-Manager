#include "stdafx.h"
#include "Mobile.h"
#include "DigitalEquitment.h"
#include <string>
using namespace std;

Mobile::Mobile(string code, string name, string brand, int number, string details, int price, int size, string color)
{
	DigitalEquitment(code, name, brand, number, details, price);
	this->size = size;
	this->color = color;
}


Mobile::~Mobile()
{
}
