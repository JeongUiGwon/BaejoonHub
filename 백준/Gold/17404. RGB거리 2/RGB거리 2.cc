#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 987654321;
int rgb[1000][3];
int dp[1000][3];

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];

	int ans = MAX;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j) dp[0][j] = rgb[0][j];
			else dp[0][j] = MAX;
		}

		for (int j = 1; j < N; j++)
		{
			dp[j][0] = rgb[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = rgb[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = rgb[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j) continue;
			else ans = min(ans, dp[N - 1][j]);
		}
	}

	cout << ans;

	return 0;
}