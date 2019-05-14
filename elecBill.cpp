/* C++ program to model electrity bill generator
 * 		Written By: Ramchandra Shahi Thakuri
 * 		Date:
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class ebill
{
	private:
		char name[20];
		float units, charge, surcharge;

	public:
		void input();
		void calc();
		void display();
};

void ebill :: input()
{
	cout << "\nEnter name of user: ";
	cin >> name;
	cout << "\nEnter unites consumed: ";
	cin >> units;
}

void ebill :: display()
{
	cout << "\nName of User: " << name;
	cout << "\nUnits Consumed: " << units;
	cout << "\nAmount Charged: " << charge;
	cout << "\nSurcharge Amount: " << surcharge;
	cout << endl;
}

void ebill :: calc()
{
	if(units < 100)
	{
		charge = (units * 1.5) + 50;
	}
	else if(units < 200)
	{
		charge = 50 + (100 * 1.5) + (units - 100) * 1.8;
	}
	else
	{
		charge = 50 + (100 * 1.5) + (100 * 1.8) + (units - 200) * 2.5;
	}

	if(units > 300)
	{
		surcharge = (charge * 0.15);
		charge += surcharge;
	}
}

int main()
{
	ebill *users;
	int n;

	system("clear");
	cout << "\t\t\tElectricty bill generator\n";
	cout << "Enter no of user: ";
	cin >> n;

	users = new ebill[n];

	for(int i = 0; i < n; i++)
	{
		users[i].input();
		users[i].calc();
	}

	for(int i = 0; i < n; i++)	
		users[i].display();
	return 0;
}

