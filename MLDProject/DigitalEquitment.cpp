#include "stdafx.h"
#include "DigitalEquitment.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

string allThing;
using namespace std;
DigitalEquitment::DigitalEquitment(){};


DigitalEquitment::DigitalEquitment(string code, string name, string brand, int number, string details, int price)
{		 
	 this->code=code;
	 this->name = name;
	 this->brand = brand;
	 this->number = number;
	 this->details = details;
	 this->price = price;
};
DigitalEquitment::DigitalEquitment(string code, string name, string brand, int number, string details, int price, string otherThing){
	this->code = code;
	this->name = name;
	this->brand = brand;
	this->number = number;
	this->details = details;
	this->price = price;
	this->otherThing = otherThing;
};
DigitalEquitment::DigitalEquitment(string code){
	this->code = code;
};
DigitalEquitment::DigitalEquitment(string code, int number){
	this->code = code;
	
	this->number = number;
};

DigitalEquitment::~DigitalEquitment()
{
}
int DigitalEquitment::search(){
	ifstream input(fileName);
	string codeFromFile;
	while (input){
		input >> codeFromFile;
		if (codeFromFile == code){
			int filePointerAddres = input.tellg();
			return filePointerAddres;
		}
		else{
			string info;
			getline(input, info);
		}
	}
}
void DigitalEquitment::searchEquitment(){
	ifstream findEquitment(fileName);
	int filePointerAddress = search();

	findEquitment.seekg(filePointerAddress,ios::beg );
	string info;
	getline(findEquitment, info);
	cout << "equitment information -> " <<code<< info << endl;
};

void DigitalEquitment::editEquitment(){
	ifstream input(fileName);
	string allThing;
	string codeFromFile;
	string info;
	string allInfo;
	
	while (input){
		input >> codeFromFile;
		getline(input, info);
		if (allInfo != codeFromFile + info){
			if (codeFromFile == code){
				cout << "information =->" << codeFromFile << info << endl;
				cout << "!_enter new information_!" << endl;
				string edit;
				getline(cin, edit);

				if (edit != allInfo){

					allThing += edit;
					allThing += "\n";
					allInfo = codeFromFile + info;
				}
			}
			else{
				if (allInfo != code + info){
					allInfo = codeFromFile + info;
					allThing += allInfo;
					allThing += "\n";
				}
			}
		}
	}

	input.close();
	fstream outToFile;
	outToFile.open(fileName, ios::out);
	outToFile << allThing << endl;

}
void DigitalEquitment::addNewEquitment( ){
	// convert object value to one string
	string allInfo;
	allInfo += code+" ";
	allInfo += name + " ";
	allInfo += brand + " ";
	string number1 = to_string(number);
	allInfo += number1 + " ";
	allInfo += details + " ";
	string price1 = to_string(price);
	allInfo += price1 + " ";
	allInfo += otherThing;
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


void DigitalEquitment::printAllEquitment(){
	ifstream print(fileName);
	while (print){
		string equitmentInformation;
		getline(print, equitmentInformation);
		cout << equitmentInformation << endl;
	}


}



//void DigitalEquitment::sell(){
//	ifstream input(fileName);
//	string codeFromFile;
//	string allThing;
//	string allInfo;
//	string info;
//	bool s = true;
//	while (input){
//		input >> codeFromFile;
//		
//		if (codeFromFile + info != allInfo){
//			if (codeFromFile == code){
//				allInfo += codeFromFile;
//				string InfoFromFile;
//				allInfo += InfoFromFile + " ";
//				input >> InfoFromFile;
//				allInfo += InfoFromFile+" ";
//				input >> InfoFromFile;
//				allInfo += InfoFromFile + " ";
//				input >> InfoFromFile;
//				string fileNumber1 = InfoFromFile;
//				int fileNumber = stoi(fileNumber1);
//				if (this->number <= fileNumber){
//					fileNumber -= this->number;
//					string newNumber = to_string(fileNumber);
//					allInfo += newNumber + " ";
//				}
//				else{
//					s = false;
//				}
//				getline(input, info);
//				allInfo += info;
//				allThing += allInfo;
//				allThing += "\n";
//			}
//			if (codeFromFile != code){
//				allThing += codeFromFile;
//				getline(input, info);
//				allThing += info;
//				allThing += "\n";
//				allInfo = codeFromFile + info;
//			}
//		}
//	}
//	input.close();
//	if (s == true){
//		cout << "!-Sales completed-!" << endl;
//		ofstream output(fileName);
//		output << allThing << endl;
//	}
//	else{
//		cout << "Sales failed because the device did not have the desired number";
//	}
//}

void DigitalEquitment::sell(){
	ifstream input(fileName);
	string codeFromFile;
	string info;
	string allInfo;// this have one line and this is add to allLine
	string allLine;// this string have every thing from file and new number for sell
	while (input){
		input >> codeFromFile;
		string codeFromFile2 = codeFromFile;
		if (codeFromFile+info!=allInfo){
			if (codeFromFile == code){
				allInfo += codeFromFile + " ";
				input >> codeFromFile;
				allInfo += codeFromFile + " ";
				input >> codeFromFile;
				allInfo += codeFromFile + " ";
				input >> codeFromFile;// codeFromFile==number
				string fileNumber = codeFromFile;
				int equitmentNumber = stoi(fileNumber);
				if (this->number <= equitmentNumber){
					cout << "sell completed" << endl;
					equitmentNumber += this->number;
					string newEquitmentNumber = to_string(equitmentNumber);
					allInfo += newEquitmentNumber;
					getline(input, info);
					allInfo += info;
					allLine += allInfo;
					allLine += "\n";
				}
				else{
					cout << "Sale failed";
					getline(input, info);
					allInfo += info;
					allLine += allInfo;
					allLine += "\n";
				}
				}

			if (codeFromFile2 != code){
				getline(input , info);
				allLine += codeFromFile2;
				allInfo += info;
				allLine += allInfo;
				allLine += "\n";
			}

			}
	}
	input.close();
	ofstream output;
	output.open(fileName, ios::out);
	output << allLine << endl;
}