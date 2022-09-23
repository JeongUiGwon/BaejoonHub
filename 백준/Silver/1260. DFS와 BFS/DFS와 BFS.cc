#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, V;
int visited[1003];
int visited2[1002];
vector<int> edges[10005];

void dfs(int now)
{
	for (int i = 0; i < edges[now].size(); i++)
	{
		int next = edges[now][i];

		if (visited[next] == 1) continue;

		visited[next] = 1;
		printf("%d ", next);
		dfs(next);
	}
}

void bfs()
{
	queue<int> q;
	visited2[V] = 1;
	printf("%d ", V);
	q.push(V);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < edges[now].size(); i++)
		{
			int next = edges[now][i];

			if (visited2[next] == 1) continue;

			visited2[next] = 1;
			printf("%d ", next);
			q.push(next);
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++)
	{
		int st, en;
		scanf("%d %d", &st, &en);

		edges[st].push_back(en);
		edges[en].push_back(st);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(edges[i].begin(), edges[i].end());
	}

	visited[V] = 1;
	printf("%d ", V);
	dfs(V);

	printf("\n");

	bfs();

	return 0;
}