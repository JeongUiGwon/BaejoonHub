#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int parent_node;
int visited[100005];
int parent[100005];
vector<int> edges[100005];

void bfs() {
	queue<int> q;
	visited[1] = 1;
	q.push(1);

	while (!q.empty()) {
		int cur_node = q.front();
		q.pop();

		for (int i = 0; i < edges[cur_node].size(); i++) {
			int next_node = edges[cur_node][i];
			if (visited[next_node]) continue;

			visited[next_node] = 1;
			q.push(next_node);
			parent[next_node] = cur_node;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	bfs();

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}