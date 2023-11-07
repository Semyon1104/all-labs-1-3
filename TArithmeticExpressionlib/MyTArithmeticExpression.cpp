#include "MyTArithmeticExpression.h"
#include "Mystack.cpp"

TArithmeticExpression::TArithmeticExpression(string infx) : infix(infx)
{
	priority = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
	ToPostfix();
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
			operands.insert({ item, 0.0 });
			postfix += item;
		} // switch
	} // for
	while (!st.IsEmpty()) {
		stackItem = st.Get();
		postfix += stackItem;
	}
}
vector<char>  TArithmeticExpression::GetOperands() const
{
	vector<char> op;
	for (const auto& item : operands)
		op.push_back(item.first);
	return op;
}

double TArithmeticExpression::Calculate(const map<char, double>& values)
{
	for (auto& val : values)
	{
		try
		{
			operands.at(val.first) = val.second;
		}
		catch (out_of_range& e) {}
	}
	TStack<double> st(infix.length() - 1);
	double leftOperand, rightOperand;
	for (char lexem : postfix)
	{
		switch (lexem)
		{
		case '+':
			rightOperand = st.Get();
			leftOperand = st.Get();
			st.Push(leftOperand + rightOperand);
			break;
		case '-':
			rightOperand = st.Get();
			leftOperand = st.Get();
			st.Push(leftOperand - rightOperand);
			break;
		case '*':
			rightOperand = st.Get();
			leftOperand = st.Get();
			st.Push(leftOperand * rightOperand);
			break;
		case '/':
			rightOperand = st.Get();
			leftOperand = st.Get();
			st.Push(leftOperand / rightOperand);
			break;
		default:
			st.Push(operands[lexem]);
		}
	}
	return st.Get();
}

