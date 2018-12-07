#include <iostream>
#include <vector>
using namespace std;

int main()
{
	// 3 ways to create the same vector
	vector<int> v1 = { 2,4,6,8 };

	vector<int> v2;
	for (int n = 2; n <= 8; n += 2)
		v2.push_back(n);

	vector<int> v3(4);
	for (int n = 1; n <= 4; n++)
		v3[n - 1] = n * 2;

	// Display elementwise
	for (int n = 0; n < v1.size(); n++)
		cout << v1[n] << endl;

	for (int n : v2)
		cout << n << endl;

	system("pause");
	return 0;
}
