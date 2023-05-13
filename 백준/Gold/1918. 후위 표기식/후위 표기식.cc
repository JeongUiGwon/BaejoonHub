#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char ch)
{
	switch (ch)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string formula;
	stack<char> op;
	cin >> formula;

	for (int i = 0; i < formula.length(); i++) 
	{
		if (formula[i] >= 'A' && formula[i] <= 'Z') 
			cout << formula[i];
		else if (formula[i] == '(')
			op.push(formula[i]);
		else if (formula[i] == ')')
		{
			while (op.top() != '(')
			{
				cout << op.top();
				op.pop();
			}
			op.pop();
		}
		else
		{
			while (!op.empty() && priority(op.top()) >= priority(formula[i]))
			{
				cout << op.top();
				op.pop();
			}
			op.push(formula[i]);
		}
	}

	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}

	return 0;
}