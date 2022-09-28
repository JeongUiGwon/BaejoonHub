#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int visited[101];
unordered_map<int, int> ladders;
unordered_map<int, int> snakes;

void bfs() {
	queue<pair<int, int>> q;
	visited[1] = 1;
	q.push({ 1, 0 });

	while (!q.empty()) {
		int cur_pos = q.front().first;
		int cur_cnt = q.front().second;
		q.pop();

		if (cur_pos == 100) {
			cout << cur_cnt;
			return;
		}

		for (int i = 1; i <= 6; i++) {
			int next_pos = cur_pos + i;

			if (next_pos > 100) continue;
			if (snakes[next_pos]) next_pos = snakes[next_pos];
			if (ladders[next_pos]) next_pos = ladders[next_pos];
			if (visited[next_pos] == 1) continue;

			visited[next_pos] = 1;
			q.push({ next_pos, cur_cnt + 1 });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;		
		ladders[x] = y;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		snakes[u] = v;
	}

	bfs();

	return 0;
}