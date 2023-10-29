#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101][10001];
int memory[101];
int cost[101];


// 5 60
// 30	10	20	35	40
// 3	0	3	5	4

/*
		0	1	2	3	4	5
	0
	1	0	
	2	0	0	3	3	3	INF	INF	
	3	0	0	3	3	6	6	6
	4	0	0	3	3	6	6	6
	5	0	0	
*/


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, max_cost = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> memory[i];

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i];
		max_cost += cost[i];
	}


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= max_cost; j++)
		{
			if (j - cost[i] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
			else
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	for (int i = 0; i <= max_cost; i++)
	{
		if (dp[N][i] >= M)
		{
			cout << i;
			break;
		}
	}

	return 0;
}