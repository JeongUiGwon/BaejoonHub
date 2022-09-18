#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int min_num, max_num;
	if (a > b)
	{
		max_num = a;
		min_num = b;
	}
	else
	{
		max_num = b;
		min_num = a;
	}

	int gcf = 1;
	for (int i = 1; i <= a; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			gcf = i;
		}
	}

	int lcm = 1;
	for (int i = a; i < INF; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			lcm = i;
			break;
		}
	}

	cout << gcf << '\n' << lcm;

	return 0;
}