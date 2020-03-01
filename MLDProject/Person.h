#pragma once
#include <fstream>

using namespace std;
class Person
{
private :
	const string personFile = "customer.txt";
	string personCode;
	string firstName;
	string lastName;
	string personPhoneNumber;
public:
	
	Person(string code, string firstName, string lastName, string phoneNumber);
	Person(string code);
	~Person();
	void addNew();
	void edit();
	void search();
};

