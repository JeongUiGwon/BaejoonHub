#include <iostream>
#include <vector>
#include <queue>

#define INF 123456789

using namespace std;

int N, M, start_city, end_city;
int dist[1003];
vector<int> path[1003];
vector<pair<int, int>> graph[1003];

void dijkstra(int start) {
	fill(dist, dist + 1003, INF);

	dist[start] = 0;
	path[start].push_back(start);

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		int now = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[now] < cost) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].second;
			int nextDist = cost + graph[now][i].first;

			if (dist[next] > nextDist) {
				dist[next] = nextDist;

				path[next] = path[now];
				path[next].push_back(next);
				pq.push({ nextDist, next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].push_back({ cost, end });
	}

	cin >> start_city >> end_city;

	dijkstra(start_city);

	cout << dist[end_city] << '\n';
	cout << path[end_city].size() << '\n';
	
	for (int i = 0; i < path[end_city].size(); i++) {
		cout << path[end_city][i] << " ";
	}
}