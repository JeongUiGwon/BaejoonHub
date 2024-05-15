#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_N 16
#define INF 987654321

using namespace std;

int N;
int W[MAX_N][MAX_N];
int dp[MAX_N][1 << MAX_N];

int dfs(int cur, int visited) {

	// 탐색 완료한 경우,
	if (visited == (1 << N) - 1) {
		if (W[cur][0] == 0) return INF;	// 이동 불가한 경우,
		return W[cur][0];	// 이동 가능한 경우,
	}

	// 이미 탐색한 경우,
	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	dp[cur][visited] = INF;	// 초기화

	// 모든 도시 탐색
	for (int i = 0; i < N; i++) {
		if (W[cur][i] == 0) continue;	// 이동 불가한 경우,
		if ((visited & (1 << i))) continue;	// 이미 방문한 경우,

		dp[cur][visited] = min(dp[cur][visited], W[cur][i] + dfs(i, visited | 1 << i));
	}

	return dp[cur][visited];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> W[i][j];

	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1);

	return 0;
}