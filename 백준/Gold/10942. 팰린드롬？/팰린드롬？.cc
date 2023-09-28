#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[2003][2003];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, S, E;
	vector<int> v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = 0; i < N; i++)
		dp[i][i] = 1;

	for (int i = 0; i < N - 1; i++)
		if (v[i] == v[i + 1]) dp[i][i + 1] = 1;

	for (int i = N - 1; i >= 0; i--)
		for (int j = i + 2; j < N; j++)
			if (v[i] == v[j] && dp[i + 1][j - 1]) dp[i][j] = 1;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> S >> E;
		cout << dp[S - 1][E - 1] << "\n";
	}

	return 0;
}