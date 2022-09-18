#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int dat_comb[100][100];

int Combination(int n, int r)
{
	if (n == r || n == 0 || r == 0)
	{
		dat_comb[n][r] = 1;
		return 1;
	}

	if (dat_comb[n][r] != 0)
	{
		return dat_comb[n][r];
	}

	dat_comb[n][r] = Combination(n - 1, r - 1) + Combination(n - 1, r);

	return dat_comb[n][r];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << Combination(N, K);

	return 0;
}