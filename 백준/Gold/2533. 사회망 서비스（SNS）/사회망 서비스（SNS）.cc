#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000006

using namespace std;

int N;
vector<int> graph[MAX_N];
int dp[MAX_N][2]; // dp[x][y] = x번 노드가 0(얼리 아답터) 또는 1(일반인) 경우,
bool visited[MAX_N];

void dfs(int cur)
{
	visited[cur] = true;
	dp[cur][0] = 1;	// 얼리 아답터인 경우 1

	// 1. 현재 노드가 0(얼리 아답터)인 경우, dp[현재 노드][얼리 아답터] += min(dp[다음 탐색 노드][얼리 아답터], dp[다음 탐색 노드][일반인])
	// 2. 현재 노드가 1(일반인)인 경우, dp[현재 노드][일반인] += dp[다음 탐색 노드][얼리 아답터]
	for (int i = 0; i < graph[cur].size(); i++) {
		int next = graph[cur][i];
		if (visited[next]) continue;

		dfs(next);	// 다음 노드 탐색

		// 점화식
		dp[cur][0] += min(dp[next][1], dp[next][0]);
		dp[cur][1] += dp[next][0];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N : 정점 개수
	cin >> N;

	// 그래프 입력
	for (int i = 0; i < N; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	// 1번부터 탐색
	dfs(1);

	// 1번이 얼리 아답터인 경우와 일반인인 경우, 총 2개의 경우 중에서 작은 값 출력
	cout << min(dp[1][0], dp[1][1]);

	return 0;
}