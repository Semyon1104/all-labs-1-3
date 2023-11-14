#include "MyTArithmeticExpression.h"

#include <iostream>
using namespace std;
int main()
{
	string exprStr;
	cout << "Enter expression :";
	cin >> exprStr;
	TArithmeticExpression expr(exprStr);
	cout << expr.GetInfix() << endl;
	cout << expr.GetPostfix() << endl;

	//map<char, double> values;
	//double val;
	//int i = 0;
	//for (const auto& op : operands)
	//{
	//	/*cout << "Enter value of " << op << ": ";
	//	cin >> val;*/
	//	val = operands[i];
	//	i++;
	//	values[op] = val;
	//}
	cout << expr.Calculate() << endl;
	setlocale(LC_ALL, "Russian");
}

