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
	Person obj("10", "ali", "hassani","09020000");
	obj.addNew();
	system("pause");
	return 0;
}

