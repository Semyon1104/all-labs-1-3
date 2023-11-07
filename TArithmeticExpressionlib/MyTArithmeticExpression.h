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
	vector<char> GetOperands() const;
	double Calculate(const map<char, double>& values);
};