#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000006

using namespace std;

int N;
vector<int> graph[MAX_N];
int dp[MAX_N][2];
bool visited[MAX_N];

void dfs(int cur)
{
	visited[cur] = true;
	dp[cur][0] = 1;

	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (visited[next]) continue;

		dfs(next);
		dp[cur][1] += dp[next][0];
		dp[cur][0] += min(dp[next][1], dp[next][0]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]);

	return 0;
}