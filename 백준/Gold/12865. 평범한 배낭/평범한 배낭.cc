#include <iostream>
#include <vector>
using namespace std;

int N, K;
int dp[101][100005];
pair<int, int> items[101];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> items[i].first >> items[i].second;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - items[i].first >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - items[i].first] + items[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];

	return 0;
}