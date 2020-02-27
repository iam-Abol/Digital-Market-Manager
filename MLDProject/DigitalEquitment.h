#pragma once
#include <fstream>

using namespace std;
class DigitalEquitment 
{
private :
	const string fileName = "items.txt";
	string code;
	string name;
	string brand;
	int number;
	string details;
	int price;
public:
	DigitalEquitment();
	DigitalEquitment(string code1, string name1, string brand, int n1, string details1, int price1);
	DigitalEquitment(string code1);
	~DigitalEquitment();
	void addNewEquitment();
	void editEquitment();
	void printAllEquitment();
	void searchEquitment(string searchcode);
	void writeToFile();
};

