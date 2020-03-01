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
	string otherThing;
public:
	DigitalEquitment();
	DigitalEquitment(string code, string name, string brand, int number, string details, int price);
	DigitalEquitment(string code, string name, string brand, int number, string details, int price,string otherThing);
	DigitalEquitment(string code);
	DigitalEquitment(string code,int number);
	~DigitalEquitment();
	int search();
	void addNewEquitment();
	void editEquitment();
	void printAllEquitment();
	void searchEquitment();
	void writeToFile();
	//void sell();
	void sell();
};

