#include <iostream>
#include <string>
using namespace std;

void swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int main()
{
	int x = 1, y = 2;
	swap(&x, &y);
	cout << "x: " << x << '\n'
		<< "y: " << y << endl;

	system("pause");
	return 0;
}
