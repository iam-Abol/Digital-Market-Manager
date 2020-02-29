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
	DigitalEquitment obj("2");
	obj.editEquitment();
	system("pause");
	return 0;
}

