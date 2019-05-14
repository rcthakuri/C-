/* C++ program to demonstrate complex number addition
 *		Written By: Ramchandra Shahi Thakuri
 *		Date:
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class Complex
{
	private:
		float x;
		float y;

	public:
		void input(float real, float img)
		{
			x = real;
			y = img;
		}
		void show()
		{
			cout << "\n " << x << " + " << y << "j" << endl;
		}

		friend Complex sum(Complex, Complex);
};

Complex sum(Complex c1, Complex c2)
{
	Complex c3;
	c3.x = c1.x + c2.x;
	c3.y = c1.y + c2.y;
	return c3;
}


int main()
{
	Complex c1, c2, c3;
	c1.input(1.2, 2.3);
	c2.input(1.2, 2.3);

	c1.show();
	c2.show();
	c3 = sum(c1, c2);
	c3.show();
	return 0;
}
