#pragma once
#include <string>
class Sell
{
private :
    const std::string sellFile = "sell.txt";
	std::string personCode;
	std::string equitmentCode;
	std::string number;
public:
	Sell();
	Sell(std::string personCode1,std::string equitmentCode,std::string numbere1);
	~Sell();
	void sell();
};

