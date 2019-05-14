/* C++ program for number conversion for hexa and octal number
 * 		Written By: Ramchandra Shahi Thakuri
 * 		Date: 
 */

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

class num
{
	public:
		char hexaN[100];
		int octN;
};

class hexa : public num
{
	public:
		int val1;

		hexa()
		{
			val1 = 0;
		}

		void read()
		{
			cout << "\nEnter hexadecimal number: ";
			cin >> hexaN;
		}

		int hexaToDec()
		{
			int term;
			int len;

			len = strlen(hexaN);

			for(int i; hexaN[i] != '\0'; i++)
			{
				len--;

				if(hexaN[i] >= '0' && hexaN[i] <= '9')
					term = hexaN[i] - 48;
				else if(hexaN[i] >= 'a' && hexaN[i] <= 'f')
					term = hexaN[i] - 87;
				else if(hexaN[i] >= 'A' && hexaN[i] <= 'F')
					term = hexaN[i] - 55;
				val1 += term * pow(16, len);
			}
			return val1;
		}

};

class octal : public num
{
	public:
		int val2;

		octal()
		{
			val2 = 0;
		}

		void read()
		{
			cout << "\nEnter octal number: ";
			cin >> octN;
		}

		int octToDec()
		{
			int temp;
			int i;
			temp = octN;
			i = 0;
			while(temp != 0)
			{
				temp %= 10;
				val2 += temp * pow(8, i++);
				temp /= 10;
			}
			return val2;
		}
}
int operator +(hexa h, octal o)
{
	int k;
	k = h.val1 + o.val2;
	return k;
}

int operator +(octal o, int num)
{
	int k;
	k = o.val2 + num;
	return k;
}
		
int main()
{
	hexa h;
	octal o;
	int val;

	system("clear");
	cout << "\t\t\tNumber conversion program\n";
	h.read();
	val = h.hexaToDec();
	cout << "\nHexa to decimal is " << val << endl;
	o.read();
	val = o.octToDec();
	cout << "\nOctal to decimal is " << val << endl;

	cout << "\n\n" << h.val1 << "+" << o.val2 << " = " << h.val1 + o.val2 << endl;
	cout << "\nEnter number to add in hexa and oct number: ";
	cin >> val;
	cout <<  "\nOctal + Num:\n";
	cout << "\n\n" << o.val2 << "+" << val << " = " << o.val2 + val << endl;
	return 0;
}

