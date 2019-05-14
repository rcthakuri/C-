/* C++ progra to demonstrate vector and list class and it's predfined methods for sorting int 
 * 		Written By: Ramchandra Shahi Thakuri
 * 		Date:
 */

#include <iostream>
#include <vector>
#include <list>
#include <stdlib.h>

using namespace std;
void display(vector <int> &v2)
{
	int i;
	
	cout << "\nContents of v2 are: \n";
	for(i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}
}

void displayList(list <int> &l)
{
	list <int> :: iterator p;

	cout << "\nContents of list are: \n";

	for(p = l.begin(); p != l.end(); p++)
	{
		cout << *p << endl;
	}
}

int main()
{
	vector <int> v1;
	int x;
	int i;

	system("clear");

	cout << "\t\t\tC++ program to demonstrate vector and list class\n";
	cout << "Enter 5 unsorted integer number \n";

	for(i = 0; i < 5; i++)
	{
		cin >> x;
		v1.push_back(x);
	}

	list <int> l;

	//now putting v1 elem to l and sort it on l 
	copy(v1.begin(), v1.end(), back_inserter(l));

	l.sort();

	displayList(l);

	vector <int> v2;

	copy(l.begin(), l.end(), back_inserter(v2));

	display(v2);
	return 0;
}

