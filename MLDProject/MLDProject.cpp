#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DigitalEquitment.h"
#include "Mobile.h"
#include "Notebook.h"
#include <vector>
#include "Person.h"

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{

	system("color 4");
	DigitalEquitment obj("1", 10);
	obj.sell();
	cout << "1-Digital Equitment Management." << endl;
	cout << "2-Members Management." << endl;
	cout << "3-Digital Equitment Sale." << endl;
	cout << "4-Lottery." << endl;
	int n;
	cin >> n;
	if (n == 1){
		cout << "1-Add New Equitment." << endl;
		cout << "2-Edit Equitment." << endl;
		cout << "3-Search Equitment." << endl;
		cout << "4-Show All Equitment." << endl;
		int choose;
		cin >> choose;
		string code;
		string name;
		string brand;
		int number;
		string details;
		int price;
		string otherThing = "";
		if (choose == 1){
			cout << "enter the code : " << endl;
			cin >> code;
			cout << "enter the name : " << endl;
			cin >> name;
			cout << "enter the brand : " << endl;
			cin >> brand;
			cout << "enter the number : " << endl;
			cin >> number;
			cout << "enter the details : " << endl;
			cin >> details;
			cout << "enter the price : " << endl;
			cin >> price;

			if (name == "mobile" || name == "notebook"){
				cout << "enter other information : " << endl;
				cin >> otherThing;
			}
			DigitalEquitment obj(code, name, brand, number, details, price, otherThing);
			obj.addNewEquitment();
		}
		if (choose == 2){
			cout << "enter equitment code for editing : " << endl;
			getline(cin, code);
			DigitalEquitment objForEditing(code);
			objForEditing.editEquitment();
		}
		if (choose == 3){
			cout << "enter equitment code for search :" << endl;
			getline(cin, code);
			DigitalEquitment objForSearch(code);
			objForSearch.searchEquitment();
		}
		if (choose == 4){
			DigitalEquitment objForShowAllEquitmentInformation("");
			objForShowAllEquitmentInformation.printAllEquitment();
		}

	}
	if (n == 2){
		cout << "1-Add New Member." << endl;
		cout << "2-Edit Member Information." << endl;
		cout << "3-Member Search." << endl;
		int choose;
		cin >> choose;
		string code;
		string firstName;
		string lastName;
		string phoneNumber;
		if (choose == 1){
			cout << "enter persin code , name , last name , phone number : ";
			string allInfo;
			getline(cin, allInfo);

			Person onjForAddNewMember(allInfo);
			onjForAddNewMember.addNew();
		}
		if (choose == 2){
			cout << "enter the member code for editing : " << endl;
			getline(cin, code);
			Person objForEdit(code);
			objForEdit.edit();
		}
		if (choose == 3){
			cout << "enter the code for search : " << endl;
			getline(cin, code);
			Person objForSearch(code);
			objForSearch.search();
		}
	}
	if (n == 3){
		cout << "enter the your code : " << endl;
		string personCode;
		cin >> personCode;

		cout << "enter the equitment code : " << endl;
		string equitmentCode;
		cin >> equitmentCode;

		int number;
		cout << "enter the number of equitment you want to buy : " << endl;
		cin >> number;
		DigitalEquitment objForSelling(equitmentCode, number);
		// = 
		bool sell = objForSelling.sell();
		if (sell == true){
			cout << "sell completed\n";
			string allSellingInformation;
			allSellingInformation += personCode + " " + equitmentCode + " ";
			string equitmentNumberAfterSell = to_string(number);
			allSellingInformation += equitmentNumberAfterSell;
		}
		else{
			cout << "sell fail" << endl;
		}

	}
	if (n == 4){
		DigitalEquitment objForchooseEquitment("");
		Person objForChoosePerson("");
		objForChoosePerson.lottery();
		objForchooseEquitment.lottery();
	}



	system("pause");
	return 0;
}

