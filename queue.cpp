/* C++ program to implement queue	
 * 	Queue is kind of data structure in which, we insert data from rear end and delete from front end(for array implementation), and it is FIFI ds
 * 			Written By: Ramchandra Shahi Thakuri
 * 			Date:
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

template <class T>

class queue
{
	private:
		T a[10];
		int f;
		int r;
		int SIZE;

	public:
		queue(int n)
		{
			f = 0;
			r = -1;
			SIZE = n;
		}

		void insert_rear();
		void delete_front();
		void display();
};

template <class T> void queue <T> :: insert_rear()
{
	T item;

	if(r == SIZE - 1)
	{
		cout << "\nQueue overflow, item can not be inserted\n";
		return;
	}
	cout << "\nEnter item to be inserted: ";
	cin >> item;

	a[++r] = item;
	return;
}

template <class T> void queue <T> :: delete_front()
{
	if(f > r)
	{
		cout << "\nQueue is underflow, can not delete item\n";
		return;
	}
	cout << "\nItem deleted is " << a[f++] << endl;
	return;
}

template <class T> void queue <T> :: display()
{
	if(f > r)
	{
		cout << "\nQueue is underflow, not item to display\n";
		return;
	}

	cout << "\nQueue item are: \n";

	for(int i = f; i < SIZE; i++)
	{
		cout << a[i] << endl;
	}
	return;
}

int main()
{
	system("clear");
	int n;
	cout << "Enter size of queue: ";
	cin >> n;

	//creating queue for double and int
	queue <int> q1(n);
	queue <double> q2(n);

	int ch1, ch2;
	cout << "\n1. Integer queue\n2. Double queue\nEnter your choice: ";
	cin >> ch1;

	while(1)
	{
		switch(ch1)
		{
			case 1:
				
				while(1)
				{
				cout << "\n1.Insert Queue\n2. Delete Queue\n3. Display\n4. Quit\nEnter your choice: ";
				cin >> ch2;

				switch(ch2)
				{
					case 1:
						q1.insert_rear();
						break;
					case 2:
						q1.delete_front();
						break;
					case 3:
						q1.display();
						break;
					default:
						cout << "\nThank you!\n";
						return 0;
				}
				}
			case 2:
				while(1)
				{	
				cout << "\n1.Insert Queue\n2. Delete Queue\n3. Display\n4. Quit\nEnter your choice: ";
				cin >> ch2;

				switch(ch2)
				{
					case 1:
						q2.insert_rear();
						break;
					case 2:
						q2.delete_front();
						break;
					case 3:
						q2.display();
						break;
					default:
						cout << "\nThank you!\n";
						return 0;
				}
				}

			default:
				cout << "\nInvalid choice\nPlease enter valid choice\n";

		}
	}	
	return 0;
}


