#include "stdafx.h"
#include "DigitalEquitment.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
DigitalEquitment::DigitalEquitment()
{
}


DigitalEquitment::DigitalEquitment(string code1, string name1, string brand1, int number1, string details1, int price1)
{		 
	 code=code1;
	 name=name1;
	 brand=brand1;
	 number=number1;
	 details=details1;
	 price=price1;
}

DigitalEquitment::DigitalEquitment(string code1){
	code = code1;
};


DigitalEquitment::~DigitalEquitment()
{
}



void DigitalEquitment::addNewEquitment( ){
	// convert object value to one string
	string allInfo;
	allInfo += code;
	allInfo += name;
	allInfo += brand;
	string number1 = to_string(number);
	allInfo += number1;
	allInfo += details;
	string price1 = to_string(price);
	allInfo += price1;
	/// open file
	fstream search(fileName);
	
	///search
	bool same = true;
	string line;
	while (search){

		getline(search, line);
		if (line == allInfo){
			cout << "! No A similar device is available from the imported device !" << endl;
			same = false;
			break;
		}
			
	}
	if (same == true){
		search.close();
		search.open("items.txt", ios::app);
		search << allInfo << endl;
		cout << "New device added" << endl;
		
	}
	
}

void DigitalEquitment::editEquitment(){
	// open file
	fstream search(fileName);
	string fileCode;
	string allInfo;
	string allLine;
	while (search){
		search >> fileCode;
		// if==true allline+=line
		if (fileCode != code){
			getline(search, allInfo);
			allLine += fileCode;
			allLine += allInfo;
			allLine += "\n";
		}
		//if==true show the information and then get new information and put to allline
		else{
			getline(search, allInfo);
			cout << fileCode << allInfo << endl;
			cout << "enter new information : \n";
			string newInformation;
			getline(cin, newInformation);
			allLine += fileCode;
			allLine += newInformation;
			allLine += "\n";
		}
	}
	
	cout << allLine << endl;
	search << allLine << endl;
	
}
void DigitalEquitment::printAllEquitment(){
	ifstream print(fileName);
	while (print){
		string equitmentInformation;
		getline(print, equitmentInformation);
		cout << equitmentInformation << endl;
	}


}
void DigitalEquitment::searchEquitment(string searchcode){
	ifstream findEquitment(fileName);
	while (findEquitment){
		string code;
		findEquitment >> code;
		if (code == searchcode){
			string information;
			getline(findEquitment, information);
			code += information;
			cout <<"equitment information : "<< code << endl;
		}
	}

};


