//? Exercise 3: C++ Strings
//? file: main.hpp

//! Choose the debug mode "Multi-File Console Project" to run this program.

//?----------------------------------------------------------------------------------------
//? This file is fully given. No need to modify anything in this file.
//? The purpose of the main file is to perform automatic testing on the tasks of this exercise.
//? When you run the program with the original codebase, you should notice that all tests FAIL.
//? You are expected to turn the tests to "PASS" by accomplishing the exercise's tasks.
//?----------------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;
#include "custom_string.hpp"

int passCount = 0;
int failCount = 0;

void test(const string &description, bool passCondition)
{
	string result;

	if (passCondition)
	{
		result = "PASS";
		passCount++;
	}
	else
	{
		result = "FAIL";
		failCount++;
	}

	cout << result << "\t" << description << endl;
}

#define LINE_LENGTH 110

int main()
{

	// Testing Task 1---------------------------------------------------
	cout << endl
		 << string(LINE_LENGTH, '-') << endl;
	cout << "Testing Task 1: Mutator methods" << endl;

	CustomString strTask1a("World");
	strTask1a.pushFront("Hello ");
	test("1(a). Testing pushFront(). It should add the string in front.", strTask1a.getData() == "Hello World");

	CustomString strTask1b("C++");
	strTask1b.pushBack(" Programming");
	test("1(b). Testing pushBack(). It should add string at the back", strTask1b.getData() == "C++ Programming");

	CustomString strTask1c("ABCDEF");
	string returnTask1c = strTask1c.pop(2, 3);
	test("1(c)-i.  Testing pop(). It should return the extracted string.", returnTask1c == "CDE");
	test("1(c)-ii. Testing pop(). The extracted string should be erased from the attribute accordingly.", strTask1c.getData() == "ABF");

	CustomString strTask1d("ABCDEF");
	string returnTask1d = strTask1d.popFront(3);
	test("1(d)-i.  Testing popFront(). It should return the extracted string.", returnTask1d == "ABC");
	test("1(d)-ii. Testing popFront(). The extracted string should be erased from the attribute accordingly.", strTask1d.getData() == "DEF");

	CustomString strTask1e("ABCDEF");
	string returnTask1e = strTask1e.popBack(2);
	test("1(e)-i.  Testing popBack(). It should return the extracted string.", returnTask1e == "EF");
	test("1(e)-ii. Testing popBack(). The extracted string should be erased from the attribute accordingly.", strTask1e.getData() == "ABCD");

	// Testing Task 2---------------------------------------------------
	cout << endl
		 << string(LINE_LENGTH, '-') << endl;
	cout << "Testing Task 2: Overloaded operators" << endl;

	CustomString strTask2a("abcdef");
	CustomString returnTask2a = !strTask2a;
	test("2(a). Testing operator!. It should return a CustomString with reversed data.", returnTask2a.getData() == "fedcba");

	CustomString strTask2b("XYZ ");
	CustomString returnTask2b = strTask2b * 4;
	test("2(b). Testing operator*. It should return a CustomString with repeated string.", returnTask2b.getData() == "XYZ XYZ XYZ XYZ ");

	// Testing Task 3---------------------------------------------------
	cout << endl
		 << string(LINE_LENGTH, '-') << endl;
	cout << "Testing Task 3: Conversion methods" << endl;

	CustomString strTask3a("99.50");
	double returnTask3a = strTask3a.toDouble();
	test("3(a). Testing toDouble(). It should return the corresponding value of type double", (returnTask3a + 0.5) == 100.0);

	CustomString strTask3b("One Plus Two");
	CustomString returnTask3b = strTask3b.toUpper();
	test("3(b). Testing toUpper(). It should return a CustomString with upper case string", returnTask3b.getData() == "ONE PLUS TWO");

	cout << endl
		 << endl;

	// Print test summary---------------------------------------------------

	int testCount = passCount + failCount;
	int passPercentage = (passCount * 1.0 / testCount) * 100.0;

	cout << endl << "Testing Summary:" << endl;
	cout << "Number of Test:\t" << testCount << endl;
	cout << "Number of Pass:\t" << passCount << endl;
	cout << "Number of Fail:\t" << failCount << endl;
	cout << "Pass Rate     :\t" << passPercentage << "% " << endl;


	cout << endl;
	system("pause");//
	return 0;
}
