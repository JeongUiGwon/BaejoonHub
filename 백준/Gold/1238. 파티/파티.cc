#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, X;
vector<pair<int, int>> graph[2][1001];
vector<int> dist[2];

void Dijstra(int idx) {
	dist[idx][X] = 0;

	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> q;
	q.push({ 0, X });

	while (!q.empty()) {
		int min_cost = q.top().first;
		int now = q.top().second;
		q.pop();

		if (min_cost > dist[idx][now]) continue;

		for (int i = 0; i < graph[idx][now].size(); i++) {
			int next = graph[idx][now][i].second;
			int next_cost = min_cost + graph[idx][now][i].first;

			if (next_cost < dist[idx][next]) {
				dist[idx][next] = next_cost;
				q.push({ next_cost, next });
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	// input
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int start, end, time;
		cin >> start >> end >> time;

		graph[0][start].push_back({ time, end });
		graph[1][end].push_back({ time, start });
	}

	// initial
	dist[0].resize(N + 1, INF);
	dist[1].resize(N + 1, INF);

	Dijstra(1);
	Dijstra(0);

	int res = 0;
	for (int i = 1; i <= N; i++)
		res = max(res, dist[0][i] + dist[1][i]);

	cout << res;

	return 0;
}