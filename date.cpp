/* C++ program to demonstrate date addition and subtraction
 * 		Written By: Ramchandra Shahi Thakuri
 * 		Date;
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class date
{
	private:
		int d;
		int m;
		int y;
	
	public:
		int leap(int);
		int days(int);
		void getDate(void);
		int operator -(date);
		date operator +(int);
		friend ostream &operator <<(ostream &, date);
		friend int checkDate(date, date);
};

int date :: leap(int y)
{
	if(y % 4 == 0)
		return 1;
	else
		return 0;
}

int date :: days(int m)
{
	if( m == 2)
		return 28;
	else if(m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	else
		return 30;
}

void date :: getDate(void)
{
	cout << "\nEnter days: ";
	cin >> d;
	cout << "\nEnter Month: ";
	cin >> m;
	cout << "\nEnter Year: ";
	cin >> y;
}

int date :: operator -(date d2)
{
	int leapyear;
	int count = 0;

	while(m != d2.m || y != d2.y)
	{
		d2.d++;
		count++;
		leapyear = 0;

		if(d2.m == 2)
			leapyear = d2.leap(d2.y);

		if(d2.d > (d2.days(d2.m) + leapyear))
		{
			d2.d = 1;
			d2.m++;
		}

		if(d2.m > 12)
		{
			d2.m = 1;
			d2.y++;
		}
	}
	count += (d - d2.d);
	return count;
}

date date :: operator +(int ndays)
{
	int leapyear;
	int i;

	for(i = 1; i <= ndays; i++)
	{
		d++;
		leapyear = 0;

		if(m == 2)
			leapyear = leap(y);

		if(d > ((days(m) + leapyear)))
		{
			d = 1;
			m++;
		}
		if(m > 12)
		{
			m = 1;
			y++;
		}
	}

	return *this;
}

ostream &operator <<(ostream &out, date d)
{
	out << d.d << '/' << d.m << '/' << d.y << endl;
	return out;
}

int checkDate(date d1, date d2)
{
	if(d1.y < d2.y)
		return 0;
	else if( d1.y == d2.y)
	{
		if(d1.m < d2.m)
			return 0;
		else if(d1.m == d2. m)
		{	
			if(d1.d < d2.d)
				return 0;
			else
				return 1;
		}
		else
			return 1;
	}
	else
		return 1;
}

int main()
{
	date d1;
	date d2;
	date d3;
	int ch;
	int ndays;
	int i;

	while(1)
	{
		cout << "\n1. Addition of two date\n2. Subtraction of two date\n3. Exit\nEnter your choice: ";
		cin >> ch;

		switch(ch)
		{
			case 1: 
				cout << "Enter first date: \n\n";
				d1.getDate();
				cout << "\nEnter no of days to add: ";
				cin >> ndays;
				d3 = d1 + ndays;
				cout << "Result: \n";
				cout << d3;
				break;
			case 2:
				cout << "\nnEnter first date greater than second one: \n";
				d1.getDate();
				cout << "\nEnter second date: \n";
				d2.getDate();
				i = checkDate(d1, d2);
				if(i == 1)
				{
					ndays = d1 - d2;
					cout << "\nDiff in days is: " << ndays;
				}
				else
				{
					ndays = d2 - d1;
					cout << "\nDiff in days is: " << ndays;
				}
				break;
			defaut:
				return 0;
		}
	}
	return 0;
}
				
