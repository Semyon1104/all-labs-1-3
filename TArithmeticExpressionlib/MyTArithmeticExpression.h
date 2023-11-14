#pragma once
#include <iostream>
#include <vector>
#include <map>

using namespace std;
class TArithmeticExpression
{
	string infix;
	string postfix;
	vector<char> lexems;
	map<char, int> priority;
	map<char, double> operands;
	void Parse();
	void ToPostfix();
	vector<int> num;
public:
	TArithmeticExpression(string infx);
	string GetInfix() const // почему здесь нельзя написать noexcept?
	{
		return infix;
	}
	string GetPostfix() const // почему здесь нельзя написать noexcept?
	{
		return postfix;
	}
	vector<double> GetOperands() const;
	double Calculate();
};