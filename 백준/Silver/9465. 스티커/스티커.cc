#include <iostream>
using namespace std;

int n, max_score;
int stickers[2][100005];
int dp[2][100005];

void init() {
	max_score = 0;
}

void input() {
	cin >> n;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> stickers[i][j];
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			int max_val = 0;
			int j2 = j ^ 1;

			if (i - 1 >= 0) {
				max_val = max(max_val, dp[j2][i - 1]);
			}

			if (i - 2 >= 0) {
				max_val = max(max_val, dp[0][i - 2]);
				max_val = max(max_val, dp[1][i - 2]);
			}

			dp[j][i] = stickers[j][i] + max_val;
			max_score = max(max_score, dp[j][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++) {
		init();
		input();
		solve();
		cout << max_score << "\n";
	}

	return 0;
}