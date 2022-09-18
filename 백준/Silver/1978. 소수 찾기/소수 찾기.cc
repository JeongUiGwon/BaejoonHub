#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int prime_number[1001];
vector<int> nums;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 2; i <= 1001; i++)
	{
		prime_number[i] = 1;
	}

	for (int i = 2; i < 1001; i++)
	{
		if (prime_number[i] == 0) continue;

		for (int j = 2; j < 1001; j++)
		{
			if (i * j > 1000) break;
			prime_number[i * j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		if (prime_number[n] == 1) cnt++;
	}

	cout << cnt;


	return 0;
}