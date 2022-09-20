#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

long long fibo_table[1003];

long long fibonacci(int n)
{
	if (fibo_table[n] != 0) return fibo_table[n];

	if (n == 1)
	{
		fibo_table[1] = 1;
		return 1;
	}
	if (n == 2)
	{
		fibo_table[2] = 2;
		return 2;
	}

	return fibo_table[n] = (fibonacci(n - 1) + fibonacci(n - 2)) % 10007;
}

int main()
{
	int n;
	cin >> n;

	cout << fibonacci(n);

	return 0;
}