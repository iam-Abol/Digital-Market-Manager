
#include "stdafx.h"

#include "Person.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


Person::Person(string code, string firstName, string lastName, string phoneNumber){
	this->personCode = code;
	this->firstName = firstName;
	this->lastName = lastName;

	this->personPhoneNumber = phoneNumber;
};
Person::Person(string code){
	this->personCode = code;
}
Person::~Person()
{
}

	


void Person::addNew(){
	// put every thing on one string;
	string allPersonInfo;
	allPersonInfo += personCode+" ";
	allPersonInfo += firstName + " ";
	allPersonInfo += lastName + " ";

	allPersonInfo += personPhoneNumber + " ";
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
	ifstream input(personFile);
	string codeFromFile; // this string have a code from file
	string allThing; //this string have every thing and new edit
	string info; //have person info without code
	int i = 0;
	string allInfo;
	while (input){

		input >> codeFromFile;
		getline(input, info);
		if (codeFromFile + info != allInfo){
			if (codeFromFile == personCode){
				string edit;
				cout << "person information =--> " << codeFromFile << info << endl;
				cout << "!_enter new person information_!" << endl;
				getline(cin, edit);
				allThing += edit;
				allThing += "\n";
				allInfo = codeFromFile + info;

			}
			else{
				if (allInfo != codeFromFile + info){
					allInfo = codeFromFile + info;
					allThing += allInfo;
					allThing += "\n";
				}

			}
		}
	}
	input.close();
	ofstream outputallThing;
	outputallThing.open(personFile, ios::out);
	outputallThing << allThing << endl;
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
void Person::lottery(){
	int number = rand();
	ifstream input(personFile);
	string info;
	int numberOfLine=0;
	string allInfo;
	while (input){
		getline(input, info);
		if (info != allInfo){
			numberOfLine++;
			allInfo = info;
		}
	}
	numberOfLine--;//
	int winnerLineNumber = number%numberOfLine;
	if (winnerLineNumber == 0){
		winnerLineNumber = numberOfLine;
	}
	int i = 0;
	input.close();
	ifstream lottery(personFile);
	while (lottery){
		getline(lottery, info);
		i++;
		if (i == winnerLineNumber){
			cout << info << " win :" << endl;

				
		}

	}
	
};