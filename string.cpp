/* C++ program to manipulate STRING
 * 			Written By: Ramchandra Shahi Thakuri
 * 			Date:
 */

#include <iostream>
#include <stdlib.h>
#include <string.h>


using namespace std;

class String
{
	private:
		char *str;
		int length;

	public:
		String()
		{
			length = 0;
			str = new(nothrow) char[length + 1];

			if(!str)
			{
				cout << "\nInsuff. memory\n";
				exit(0);
			}
		}

		String(char *s)
		{	
		   	length = strlen(s);
			str = new(nothrow) char[length + 1];

			if(!str)
			{
				cout << "\nInsuff. memory\n";
				exit(0);
			}
			strcpy(str, s);
		}

		friend String operator +(String, String);
		friend ostream &operator <<(ostream &, String);
};

String operator +(String s1, String s2)
{
	String s3;
	s3.length = strlen(s1.str) + strlen(s2.str);

	s3.str = new(nothrow) char[s3.length + 1];

	if(!s3.str)
	{
		cout << "\nInsuff. memory\n";
		exit(0);
	}

	strcpy(s3.str, s1.str);
	strcat(s3.str, " ");
	strcat(s3.str, s2.str);
	return s3;
}
ostream &operator <<(ostream &out, String s)
{
	out << s.str << endl;
	return out;
}

int main()
{
	String s1("Dr. Ambedkar"), s2("Institute of Technology"), s3;
	s3 = s1 + s2;
	//now displaying STRING
	cout << s1;
	cout << s2;
    	cout << s3;
	return 0;
}	
