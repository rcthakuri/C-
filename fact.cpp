/* C++ program to demonstrate custom exception handling
 *		Written By: Ramchandra Shahi Thakuri
 *		Date:
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

void fact(int);
class ide
{
	public:
		char str_what[80];
		int what;

		ide()
		{
			*str_what = 0;
			what = 0;
		}

		ide(char *s, int e)
		{
			strcpy(str_what, s);
			what = e;
		}
};

int main()
{
	int n;
	system("clear");
	cout << "\t\t\tC++ program to demonstrate custom exception handling program\n";
	cout << "Enter value of n: ";
	cin >> n;
	try
	{
		if(n < 0)
		{
			throw ide("Negative number entered", n);
		}
		else 
			fact(n);
	}
	catch(ide e)
	{
		cout << e.str_what << " : ";
		cout << e.what << endl;
	}
}

void fact(int n)
{
	int res;
	res = 1;
	cout << "\nFactorial of " << n;
	while( n != 0)
	{
		res *= n;
		n--;
	}

	cout << " is " << res << endl;
}
