#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> vect[1003];
int node[1003];

void dfs(int now)
{
	for (int i = 0; i < vect[now].size(); i++)
	{
		int next = vect[now][i];

		if (node[next] == 1) continue;

		node[next] = 1;
		dfs(next);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		vect[u].push_back(v);
		vect[v].push_back(u);
	}

	int cnt_el = 0;
	for (int i = 1; i <= N; i++)
	{
		if (node[i] == 1) continue;

		cnt_el++;
		node[i] = 1;
		dfs(i);
	}

	cout << cnt_el;

	return 0;
}