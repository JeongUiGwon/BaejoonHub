#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int d[1003];
vector<pair<int, int>> graph[1003];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (d[now] < dist)
			continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int cost = dist + graph[now][i].second;
			
			if (cost < d[graph[now][i].first]) {
				d[graph[now][i].first] = cost;
				pq.push({ -cost, graph[now][i].first });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(d, d + 1003, INF);

	int N, M;
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int st, end, cost;
		cin >> st >> end >> cost;

		graph[st].push_back({ end, cost });
	}

	int st, end;
	cin >> st >> end;

	dijkstra(st);

	cout << d[end];

	return 0;
}