
#include "stdafx.h"

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Person::Person()
{
}

Person::Person(string code,string name1, string lname1 , string phoneNumber){
	personCode = code;
	fname = name1;
	lname = lname1;

	personPhoneNumber = phoneNumber;
};
Person::Person(string code1){
	personCode = code1;
}
Person::~Person()
{
}

	


void Person::addNew(){
	// put every thing on one string;
	string allPersonInfo;
	allPersonInfo += personCode;
	allPersonInfo += fname;
	allPersonInfo += lname;

	allPersonInfo += personPhoneNumber;
	//open persen file
	fstream search(personFile);
	bool s = true;
	string line;
	while (search){
		getline(search, line);
		if (line == allPersonInfo){
			s = false;
		}
	}
	if (s == true){
		search.close();
		search.open(personFile, ios::app);
		search << allPersonInfo << endl;
		cout << " ! Member added ! " << endl;
	}
	else{
		cout << " ! Member not added because member similar to existing member exists ! \n";
	}
};
void Person::edit(){
	// in this func  get a persen code and then edit all information
};
void Person::search(){
	fstream search(personFile);
	string personCodeF;
	while (search){
		search >> personCodeF;
		if (personCodeF == personCode){
			string allInfo;
			getline(search, allInfo);
			personCodeF += allInfo;
			cout << "person information :\n" << personCodeF << endl;
		}
	}
};