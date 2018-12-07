//
//	Assignment name:	Problem Set 5 Problem 3c
//	File name:			ps5_p3c.cpp
//	Author:				Jing Zhang
//	Note:
//	Assume that the input file is cleaned.
//  (Otherwise I would clean it with Python / R to take care of missing values,
//	empty lines, mismatched positions, etc)
//	For bubble sort I wanted to use template but it's not yet covered.
//	So I used overloaded functions instead.
//	I researched what "friend" means in C++
//

#include "ps5.h"

using namespace std;

/* Problem 3c - Compute grade average for some people */
void problem3c()
{
	// Read in the grades file this time
	ifstream lineStream;
	lineStream.open(IN_FILE_GRADES);

	// Crash if things go wrong
	if (lineStream.fail())
	{
		cout << "Can't open file " << IN_FILE_GRADES << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	// Read through the file one time to get a line count
	int studentCount = 0;
	string line;
	while (!lineStream.eof())
	{
		// Read each line from the file
		getline(lineStream, line);

		// Count the number of lines as you read from the file
		studentCount++;
	}

	// Create a dynamic array large enough to store all of the students
	Student *students = nullptr;
	try
	{
		students = new Student[studentCount];
	}
	catch (bad_alloc)
	{
		cout << "Allocation Error" << endl;
	}

	// Make a constant pointer to the start of names
	Student const *start = students;

	// Read all names from the file in an array
	Student *studentPtr = students;

	// Move to the beginning to the file
	lineStream.clear();
	lineStream.seekg(0, ios::beg);

	// These 3 values gets assigned in each iteration
	string firstName, lastName;
	int grade = 0;

	// Store all objects in a dynamic array that you allocate.
	while (!lineStream.eof())
	{
		// Read each line from the file
		getline(lineStream, line);

		// When you read the numbers, compute their average for each person.
		istringstream studentStream(line);

		// The first two entries are first and last names
		studentStream >> firstName;
		studentStream >> lastName;

		// Reset in each iteration
		int gradeCount = 0;
		double gradeSum = 0;

		// The rest of them are grades
		while (!studentStream.eof())
		{
			studentStream >> grade;

			// Add them up
			gradeSum += grade;

			// Count total
			gradeCount++;
		}

		// Store the name in the array
		*studentPtr = Student(firstName, lastName, gradeSum / gradeCount);

		// Move to the next element in array
		studentPtr++;
	}

	// Lines stored, no longer need line stream
	lineStream.close();

	// Sort the objects by grade average.
	bubbleSort(students, studentCount);

	// Display all names and averages from highest to lowest.
	for (int i = studentCount - 1; i >= 0; i--)
	{
		students[i].display();
		cout << endl;
	}

	// Delete allocated memory (start is guaranteed to be not changed)
	delete[] start;
}

// Student class implementation

/* Public constructor of Student */
Student::Student(string firstName /* = "" */, string lastName /* = "" */,
	double average /* = 0 */)
{
	this->mfirstName = firstName;
	this->mlastName = lastName;
	this->mAverage = average;
}

/* Display the student's info */
void Student::display()
{
	cout << "Student: " << this->mfirstName << " "
		<< this->mlastName << endl;

	cout << "Grade Average: " << setprecision(2) << fixed
		<< this->mAverage << endl;
}

/* Overloading > operator for student (friend function, no Student::) */
bool operator>(const Student &student1, const Student &student2)
{
	// Compare by grade average
	return student1.mAverage > student2.mAverage;
}

/* Overloaded swap for Student class */
void swap(Student *studentPtr1, Student *studentPtr2)
{
	// Create a placeholder to store the value of string pointer 1
	Student temp = *studentPtr1;

	// Put the value of string pointer 2 into the value of string pointer 1
	*studentPtr1 = *studentPtr2;

	// Set the value of string pointer 2 to the placeholder
	*studentPtr2 = temp;
}

/* Overloaded bubble sort for Student class */
void bubbleSort(Student students[], unit len)
{
	unit i, j;
	bool isSwapped;

	// len - 1 because there's only n - 1 adjacent pairs in n elements
	for (i = 0; i < len - 1; i++)
	{
		// Initialize is swapped to false
		isSwapped = false;

		/* Len - i - 1 because in each outer iteration, the last element will be
		the largest (as it is "bubbled up" to the last), so we only need to look
		at n - 1 elements in the next iteration */
		for (j = 0; j < len - i - 1; j++)
		{
			// If any adjacent pair is in the wrong order
			if (students[j] > students[j + 1])	// > overloaded for string class
			{
				// Swap them (pass in the addresses of them)
				swap(&students[j], &students[j + 1]);

				// If anything is swapped, set is swapped to true
				isSwapped = true;
			}
		}

		// If nothing is swapped, then it is sorted
		if (!isSwapped)
			break;	// We are done
	}
}
