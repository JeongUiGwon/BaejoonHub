#include <iostream>
#define MOD_NUM 10e8

using namespace std;

long long dp[1 << 10][101][10];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= 9; i++)
		dp[1 << i][1][i] = 1;

	for (int n = 2; n <= N; n++) {
		for (int num = 0; num <= 9; num++) {
			for (int bit = 0; bit < (1 << 10); bit++) {
				if (num == 0)
					dp[bit | (1 << num)][n][num] += dp[bit][n - 1][num + 1] % (int)MOD_NUM;
				else if (num == 9)
					dp[bit | (1 << num)][n][num] += dp[bit][n - 1][num - 1] % (int)MOD_NUM;
				else
					dp[bit | (1 << num)][n][num] += (dp[bit][n - 1][num + 1] + dp[bit][n - 1][num - 1]) % (int)MOD_NUM;
			}
		}
	}

	long long ret = 0;

	for (int i = 0; i <= 9; i++)
		ret = (ret + dp[(1 << 10) - 1][N][i]) % (int)MOD_NUM;

	cout << ret;

	return 0;
}