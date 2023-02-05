#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

struct edge {
	int s, e, t;
};

// N : 지점의 수, M : 도로의 개수, W : 웜홀의 개수
int N, M, W;
vector<edge> edges;

// 벨만 코드 알고리즘
bool bellmanFord(int n) {
	vector<int> dist(n + 1, INF);

	dist[1] = 0;
	for (int i = 0; i < n; i++) {
		for (int pos = 0; pos < edges.size(); pos++) {
			int s = edges[pos].s;
			int e = edges[pos].e;
			int t = edges[pos].t;

			if (dist[s] + t < dist[e]) dist[e] = dist[s] + t;
		}
	}

	for (int pos = 0; pos < edges.size(); pos++) {
		int s = edges[pos].s;
		int e = edges[pos].e;
		int t = edges[pos].t;

		if (dist[e] > dist[s] + t) return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// TC : 테스트 케이스 수
	int TC;
	cin >> TC;

	for (int tc = 0; tc < TC; tc++) {
		edges.clear();

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges.push_back({ S, E, T });
			edges.push_back({ E, S, T });
		}

		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;

			edges.push_back({ S, E, -T });
		}

		if (bellmanFord(N)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}