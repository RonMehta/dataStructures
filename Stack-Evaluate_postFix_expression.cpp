//Problem Statement

//Reverse Polish notation is a mathematical notation in which every operator follows all of it's operands.
//
//Implement a Reverse Polish Notation calculator, with the following operations :
//
//: binary operator equivalent to(e.g.)
//	: unary operator equivalent to(e.g.)
//	: ternary operator equivalent to(e.g.)
//
//	All operations should be done on integers
//
//	You should use the symbols + -*/ x y z for the operators.
//
//	Input Format
//
//
//
//
//
//	...
//
//
//	Where  is the number of different reverse polish notation problems you need to solve, and  is the th problem
//
//	If the string is not parseable, or it leaves extra symbols, output NO
//
//	Output Format
//
//
//
//	...
//
//	Sample Input
//
//	2
//	3 4 - 5 +
//	3 6 /
//
//	Sample Output
//
//	4
//	0
//
//	Explanation
//
//	For the first one we do 3 - 4, getting the value of - 1, then add 5, giving us the final value of 4.
//
//	For the second one we do 3 / 6, giving us 0.


#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

bool EvaluateExperssion(string str, int &);
bool IsNumericDigit(char s);
bool IsOperator(char s);
int Operation(int i, int j, char o);

int main() {
	int testcases = 0;
	cin.clear();
	cin.sync();
	cin >> testcases;
	cin.ignore();
	vector<string> stringArr;
	for (int i = 0;i<testcases;i++)
	{
		string temp="";
		getline(cin, temp);
		stringArr.push_back(temp);
	}

	for (int i = 0;i<testcases;i++) {
		string str = stringArr[i];
		
		int value;
		bool result = EvaluateExperssion(str, value);
		if (result == true)
			cout << value << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}

bool EvaluateExperssion(string str, int & value) {

	stack<int> res;

	for (int i = 0;i<str.length();i++) {
		if (str[i] == ' ' || str[i] == ',')
			continue;

		if (IsNumericDigit(str[i]))
		{
			int operand = 0;
			while (i < str.length() && IsNumericDigit(str[i])) {

				operand = (operand * 10) + (str[i] - '0');
				i++;
			}
			i--;
			res.push(operand);
		}
		else if (IsOperator(str[i])) {

			//check if negative number
			if (str[i] == '-' && i+1 < str.length() && IsNumericDigit(str[i + 1])) {
				int operand = 0;
				i++;
				while (i < str.length() && IsNumericDigit(str[i])) {

					operand = (operand * 10) + (str[i] - '0');
					i++;
				}
				i--;
				operand *= -1;
				res.push(operand);
				continue;
			}


			int val = 0;
			if (str[i] == 'y')
			{
				if (!(res.size() >= 1))
					return false;
				val = res.top(); res.pop();
				val = (2 * val) + 1;

			}
			else if (str[i] == 'z')
			{
				if (!(res.size() >= 3))
					return false;
				int op3 = res.top(); res.pop();
				int op2 = res.top(); res.pop();
				int op1 = res.top(); res.pop();
				val = op1 + (2 * op2) + (3 * op3);

			}
			else {
				if (!(res.size() >= 2))
					return false;
				int op2 = res.top(); res.pop();
				int op1 = res.top(); res.pop();

				val = Operation(op1, op2, str[i]);
			}
			res.push(val);
		}
		else
			return false;

	}

	value = res.top();
	return true;

}

int Operation(int i, int j, char o) {

	switch (o) {
	case '+': return i + j;
	case 'x': return (pow(i,2) + j);
	case '-': return i - j;
	case '*': return i * j;
	case '/': return i / j;
	}
	return 0;
}
bool IsOperator(char s) {

	if (s == '+' || s == '-' || s == '*' || s == '/' || s == 'x' || s == 'y' || s == 'z')
		return true;
	return false;
}

bool IsNumericDigit(char s)
{
	if (s >= '0' && s <= '9')
		return true;
	return false;
}
