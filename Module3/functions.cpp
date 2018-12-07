#include <iostream>
#include <initializer_list>
using namespace std;

int multiply(int n1, int n2, double n3);
int multiply2(initializer_list<int> numbers);

int main()
{
	int z;
	z = multiply(1, 2, 3);
	z = multiply2({ 3, 4, 5, 6, 7, 8, 10 });
	cout << z << endl;

	//cout << multiply(1, 2, 3) << endl;

	system("pause");
	return 0;
}

// function example
int multiply(int n1, int n2, double n3)
{
	int prod;
	prod = n1 * n2 * n3;
	return prod;
}


// initializer_list example
int multiply2(initializer_list<int> numbers)
{
	int prod = 1;
	for (auto n : numbers)
	{
		prod = prod * n;
	}
	return prod;
}
