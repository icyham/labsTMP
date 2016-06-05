#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	char a[255], b[255]; 
	char* c;

	cout << "Enter filename: "; cin >> a;
	ifstream fin(a);
	while (!fin.eof()) 
	{
		fin.getline(a, 255);	
		if ((strstr(a, "\\func")) != NULL) 
		{ 
			c = strstr(a, "\\func");
			c += 6;
			if (strstr(c, "*/") != NULL) 
			{
				strcpy_s(b, c); 
				b[strlen(c) - 2] = '\0';
				cout << b << endl;
			}
			else
				cout << c << endl;
		}
	}
	system("pause");
	return 0;
}
