#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 32001

using namespace std;

int N, M;
int visited[MAX_N];
int inDegree[MAX_N];
vector<int> graph[MAX_N];
vector<int> path;

void topologicalSort()
{
	for (int i = 1; i <= N; i++)
	{
		if (inDegree[i] || visited[i]) continue;

		priority_queue<int, vector<int>, greater<int>> q;

		visited[i] = 1;
		q.push(i);

		while (!q.empty())
		{
			int cur = q.top();
			q.pop();
			path.push_back(cur);

			for (int j = 0; j < graph[cur].size(); j++)
			{
				int next = graph[cur][j];

				if (visited[next] || --inDegree[next] != 0) continue;

				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) 
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		inDegree[b]++;
	}

	topologicalSort();

	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";

	return 0;
}