#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dat_num[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		dat_num[num]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < dat_num[i]; j++)
		{
			cout << i << '\n';
		}
	}

	return 0;
}