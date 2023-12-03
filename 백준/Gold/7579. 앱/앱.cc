#include <iostream>
#include <algorithm>

using namespace std;

int memory_table[101];
int cost_table[101];
int dp[101][10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, sum_cost = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> memory_table[i];

	for (int i = 1; i <= N; i++)
	{
		cin >> cost_table[i];
		sum_cost += cost_table[i];
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= sum_cost; j++)
		{
			if (j - cost_table[i] >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - cost_table[i]] + memory_table[i]);

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= sum_cost; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}