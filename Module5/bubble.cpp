#include <iostream>
#include <ctime>
using namespace std;

const int SIZE = 20;

void display(int *);
void bubbleSort(int *);
void swap( int *, int *);

int main()
{
	int numbers[SIZE];
	srand(time(0));
	for (int i=0; i<SIZE; i++)
		numbers[i] = rand() % 200;
	
	display(numbers);
	bubbleSort(numbers);
	display(numbers);
		
}

void display (int *arr)
{
	for (int *p = arr; p < arr+SIZE; p++)
	  cout << *p << " " ;
	cout << endl;
}

void bubbleSort (int *arr)
{
	bool didSwap;
	int *p = arr;
	do 
	{
		didSwap = false;
		for (p = arr; p < arr + SIZE - 1; p++)
		{
			if (*p < *(p + 1))
			{
				swap(p, p + 1);
				didSwap = true;
			}
		}
	} while (didSwap);
}

void swap( int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}