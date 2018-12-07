#include <iostream>
using namespace std;

int numbers[] = { 1,3,5,7,9,4,13,2,66,4 };
const int SIZE = 10;

int * findEven()
{
	int *p = numbers;
	for (int i = 0; i < SIZE; i++,p++)
	{
		if (*p % 2 == 0)
			return p;
	}
	return nullptr;
}

int & findEven2()
{
	for (int i = 0; i < SIZE; i++)
	{
		if (numbers[i] % 2 == 0)
			return numbers[i];
	}
	cout << "no even number - fatal error\n";
	exit(-1);
}

int main()
{
	int *p;
	p = findEven();
	if (p)
		cout << *p << endl;
	else
		cout << "no even number\n";

	cout << findEven2() << endl;
	
	return 0;
}
