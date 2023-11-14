#include "MyTArithmeticExpression.h"
#include "C:\сема\2курс\АСД - прога\lab stack_queue\all-labs-1-3\stacklib\Mystack.cpp"
#include<string>
#include<iostream>

TArithmeticExpression::TArithmeticExpression(string infx) : infix(infx)
{
	priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
	ToPostfix();
	int count = 0;
	for (char c : infix)
		if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9' || c == '0' || c == '.')
			count++;
		else {
			if (count != 0)
				num.push_back(count);
			count = 0;
		}
	if (count != 0)
		num.push_back(count);
}
void TArithmeticExpression::Parse()
{
	for (char c : infix)
		lexems.push_back(c);
}
void TArithmeticExpression::ToPostfix() {
	Parse();
	TStack<char> st(infix.length()-1);
	char stackItem;
	for (char item : lexems) {
		switch (item) {
		case '(':
			st.Push(item);
			break;
		case ')':
			stackItem = st.Get();
			while (stackItem != '(') {
				postfix += stackItem;
				stackItem = st.Get();
			}
			break;
		case '+': case '-': case '*': case '/':
			while (!st.IsEmpty()) {
				stackItem = st.Get();
				if (priority[item] <= priority[stackItem])
					postfix += stackItem;
				else {
					st.Push(stackItem);
					break;
				}
			}
			st.Push(item);
			break;
		default:
			operands.insert({item, item*1.0 - 48});
			postfix += item;
		} // switch
	} // for
	while (!st.IsEmpty()) {
		stackItem = st.Get();
		postfix += stackItem;
	}
}
vector<double>  TArithmeticExpression::GetOperands() const
{
	vector<double> op;
	for (auto item : operands)
		op.push_back(item.second);
	return op;
}

double TArithmeticExpression::Calculate()
{
	TStack<double> st(infix.length() - 1);
	double a, b;
	double foradd = 0;
	int count = 0;
	int indvector = 0;
	int i = 0;
	while (i < postfix.length())
	{
		switch (postfix[i])
		{
		case '+':
			a = st.Get();
			b = st.Get();
			st.Push(a + b);
			break;
		case '-':
			a = st.Get();
			b = st.Get();
			st.Push(b - a);
			break;
		case '*':
			a = st.Get();
			b = st.Get();
			st.Push(a * b);
			break;
		case '/':
			a = st.Get();
			b = st.Get();
			st.Push(b / a);
			break;
		default:
			char* tmp = new char[100];
			for (int j = 0; j < num[indvector]; j++)
				tmp[j] = postfix[i + j];

			foradd = atof(tmp);
			i += num[indvector] - 1;
			indvector++;
			st.Push(foradd);
		}
		i++;
	}
	return st.Get();
}

