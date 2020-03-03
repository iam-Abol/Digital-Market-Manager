#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "DigitalEquitment.h"
#include "Mobile.h"
#include "Notebook.h"
#include <vector>
#include "Person.h"
int numberOfEquitment;
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	
	DigitalEquitment obj("2", "mmmobile", "huawi", 2, "1111",120000,"red");
	obj.lottery();

	system("pause");
	return 0;
}

