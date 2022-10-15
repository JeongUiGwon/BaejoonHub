#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, ans;
int color_cost[1000][3];
int dp[1000][3];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> color_cost[i][j];
}

void solve() {
	for (int i = 0; i < 3; i++)
		dp[0][i] = color_cost[0][i];

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int min_cost = INF;
			for (int k = 0; k < 3; k++) {
				if (j == k) continue;

				min_cost = min(min_cost, dp[i - 1][k]);
			}
			
			dp[i][j] = min_cost + color_cost[i][j];
		}
	}

	int min_cost = INF;
	for (int i = 0; i < 3; i++) {
		min_cost = min(min_cost, dp[N - 1][i]);
	}

	ans = min_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	cout << ans;

	return 0;
}