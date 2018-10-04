// P3_3_Application.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "..\P3_3_Library\Hex.h"

#define LINE "________________________________________________________________________________"

using namespace P3_3;
using namespace std;

/*
OPERATIONS:
0 wrong
1 +
2 -
3 <<
4 >>
5 <
6 >
7 =
*/
int selector(char *op)
{
	if (!strcmp(op, "+"))
		return 1;
	if (!strcmp(op, "-"))
		return 2;
	if (!strcmp(op, "<<"))
		return 3;
	if (!strcmp(op, ">>"))
		return 4;
	if (!strcmp(op, "<"))
		return 5;
	if (!strcmp(op, ">"))
		return 6;
	if (!strcmp(op, "="))
		return 7;
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Welcome!" << endl;
	cout << "Use this format: A op B" << endl;
	cout << "Supported operations: addition(+), subtraction(-), shift(>>/<<), comparison (</>/=)." << endl;
	cout << "Enter Ctrl + Z to stop." << endl;
	Hex a, b;
	char op[80];
	int nop, k;
	bool fl1 = true;
	while (fl1)
	{
		try
		{
			cin >> a >> op;
			nop = selector(op);
			if ((nop == 3) || (nop == 4))
				cin >> k;
			else
				cin >> b;
		}
		catch (bad_alloc &ba)
		{
			cout << "Memory allocation error: " << ba.what() << endl;
			continue;
		}
		fl1 = !cin.eof();
		if (!fl1)
			continue;
		if (cin.fail())
		{
			cout << "Wrong input!" << endl;
			cin.clear();
			continue;
		}
		try
		{
			switch (selector(op))
			{
			case 1:
				cout << " = " << (a + b);
				break;
			case 2:
				cout << " = " << (a - b);
				break;
			case 3:
				cout << " = " << (a <<= k);
				break;
			case 4:
				cout << " = " << (a >>= k);
				break;
			case 5:
				cout << " = " << (a < b);
				break;
			case 6:
				cout << " = " << (a > b);
				break;
			case 7:
				cout << " = " << (a == b);
				break;
			default:
				cout << "Wrong operation";
				break;
			}
			cout << endl;
		}
		catch (bad_alloc &ba)
		{
			cout << "Memory allocation error: " << ba.what() << endl;
			continue;
		}
		catch (exception &ex)
		{
			cout << ex.what() << endl;
		}
	}
	return 0;
}

