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
	
	
	DigitalEquitment obj1("1",1);
	obj1.sell();
	
	system("pause");
	return 0;
}

