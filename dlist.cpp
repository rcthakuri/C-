/* Program to demonstrate doubly linked list in c++ 
 * 		Written By: Ramchandra Shahi Thakuri
 * 		Date:
 */

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

//creating structure for maintaining node
struct node
{
	char data[100];
	struct node *left;
	struct node *right;
};

typedef struct node *NODE;
NODE last;

//creating class for dlink
class dlist
{
	private:
		NODE first;
		int count;
	
	public:
		dlist()
		{
			first = NULL;
			count = 1;
		}
		void insertFront();
		void delPos();
		void display();
		void insertRear();
};

void dlist :: insertFront()
{
	NODE temp;
	temp = new struct node;
	char item[100];


	cout << "Enter data to insert in linked list: ";
	cin >> item;
	
	temp -> right = NULL;
	temp -> left = NULL;

	if(first == NULL)
	{
		strcpy(temp -> data, item);
		first = temp;
		first -> left = NULL;
		first -> right = NULL;
	}
	else
	{
		strcpy(temp -> data, item);
		first -> left = temp;
		temp -> right = first;
		first = temp;
	}
}
void dlist :: insertRear()
{
	char item[100];
		
	cout << "Enter data to be inserted : ";
	cin >> item;

	NODE temp, cur, prev;

	temp = new struct node;

	temp -> right = NULL;
	temp -> left = NULL;

	if(first == NULL)
	{
		strcpy(temp -> data, item);
		first = temp;
		first -> left = NULL;
		first -> right = NULL;
	}	
	else
	{
		cur = first;
		prev = NULL; 
		while(cur -> right != NULL)
		{
			prev = cur;
			cur = cur -> right;
		}

		cur -> right = temp;
		temp -> left = cur;
		strcpy(temp -> data, item);
	}
}
		

	
void dlist :: delPos()
{
	NODE prev, cur, temp;
	int pos;
	
	if(first == NULL)
	{
		cout << "\nLinked list is empty, can not delete\n";
		return;
	}

	cout << "\nEnter position of item to delete: ";
	cin >> pos;

	if(pos == 1)
	{
		
		if(first -> right == NULL)
		{
			cout << "Item deleted is " << first -> data << endl;
			first = NULL;
			return;
		}
		cout << "Item deleted is " << first -> data << endl;
		cur = first;
		first = first -> right;
		first -> left = NULL;
		delete(cur);
		return;
	}
	prev = NULL;
	cur = first;
	while(cur -> right != NULL && count != pos)
	{
		prev = cur;
		cur = cur -> right;
		count++;
	}
	if(cur -> right == NULL)
	{
		cout << "\nItem deleted is " << cur -> data << endl;
		prev -> right = NULL;
		count = 1;
		delete(cur);
		return;
	}
		
	count = 1;
	temp = cur -> right;
	cout << "\nItem deleted is " << cur -> data << endl;
	prev -> right = temp;
	temp -> left = prev;
	delete(cur);
}

void dlist :: display()
{
	NODE cur;

	if(first == NULL)
	{
		cout << "\nList is empty, no item to display\n";
		return;
	}

	cur = first;
	cout << "\nLinked list items are: \n";
	while(cur != NULL)
	{
		cout << cur -> data << endl;
		cur = cur -> right;
	}
}

int main()
{
	dlist d;
	int choice;
	int pos;

	system("clear");


	cout << "\t\t\tProgram to demonstrate doubly linked list\n";

	while(1)
	{
		cout << "1. Insert Front\n2. Delete at Pos\n3. Display\n4. Quit\n\nEnter your choice: ";
		cin >> choice;

		switch(choice)
		{
			case 1:
				d.insertRear();
				break;
			case 2:
				d.delPos();
				break;
			case 3:
				d.display();
				break;
			default:
				cout << "\nThank you!\n";
				return 0;
		}
	}
	return 0;
}

					
