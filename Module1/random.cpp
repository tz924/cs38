#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int r1, r2, r3;
	srand(time(0));
	/* 1 to 20 (0 to 19 plus 1) */
	r1 = rand() % 20 + 1;
	r2 = rand() % 20 + 1;
	r3 = rand() % 20 + 1;
	cout << "the random numbers are: "
		<< r1 << " " << r2 << " " << r3 << endl;

	system("pause");
	return 0;
}