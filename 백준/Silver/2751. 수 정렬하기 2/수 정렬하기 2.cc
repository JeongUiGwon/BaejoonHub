#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dat[2000006];

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

		dat[num + 1000000] = 1;
	}

	for (int i = 0; i < 2000006; i++)
	{
		if (dat[i] == 1) cout << i - 1000000 << '\n';
	}

	return 0;
}