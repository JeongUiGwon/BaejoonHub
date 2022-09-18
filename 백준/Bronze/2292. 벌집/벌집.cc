#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

long long get_range_max(int val)
{
	if (val == 1) return 1;

	long long ret = 1 + 6 * val * (val - 1) / 2;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N;
	cin >> N;

	// 1 6 12 18
	//   
	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i < 100000; i++)
	{
		long long start = get_range_max(i);
		long long end = get_range_max(i + 1);

		if (N > start && N <= end)
		{
			cout << i + 1;
			break;
		}
	}

	return 0;
}