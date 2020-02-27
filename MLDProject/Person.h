#pragma once
#include <fstream>

using namespace std;
class Person
{
private :
	const string personFile = "customer.txt";
	string personCode;
	string  fname;
	string lname;
	string personPhoneNumber;
public:
	Person();
	Person(string code, string name1, string lname1, string phoneNumber);
	Person(string code1);
	~Person();
	void addNew();
	void edit();
	void search();
};

