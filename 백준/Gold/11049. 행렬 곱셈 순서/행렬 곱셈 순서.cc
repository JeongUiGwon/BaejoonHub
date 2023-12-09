#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

pair<int, int> matrix[501];
int dp[501][501];

int main()
{
	// N : 행렬의 갯수 입력
	int N, r, c;
	cin >> N;

	// 행렬 입력
	for (int i = 1; i <= N; i++)
	{
		cin >> r >> c;
		matrix[i] = { r, c };
	}

	// DP 풀이

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; i + j <= N; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + matrix[j].first * matrix[k].second * matrix[i + j].second);
		}
	}

	cout << dp[1][N];

	return 0;
}