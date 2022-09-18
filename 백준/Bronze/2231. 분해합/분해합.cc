#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int get_cal(int num) 
{
	int ret = 0;
	ret += num;

	while (num > 0)
	{
		int val = num % 10;
		ret += val;
		num /= 10;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int flag = 0;
	for (int i = 1; i < N; i++)
	{
		if (N == get_cal(i))
		{
			cout << i;
			flag = 1;
			break;
		}
	}

	if (!flag) cout << 0;

	return 0;
}