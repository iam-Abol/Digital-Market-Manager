#pragma once
#include "DigitalEquitment.h"
#include <string>

class Notebook :public DigitalEquitment
{
private:
	int size;
	std::string cpuInfo;

public:
	Notebook();
	~Notebook();
};

