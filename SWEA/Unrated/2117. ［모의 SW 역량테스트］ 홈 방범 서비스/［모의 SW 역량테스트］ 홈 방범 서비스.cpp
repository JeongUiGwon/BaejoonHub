#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
int max_home = 0;
int map[20][20];
int visited[20][20];
int dy[] = { 0, 0, 1, -1 };
int dx[] = { 1, -1, 0, 0 };

void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));

	int tmp_K = 1;
	int cnt_home = 0;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		int cur_K = visited[cur_y][cur_x];
		q.pop();

		if (tmp_K != cur_K) {
			int cost = cnt_home * M - (tmp_K * tmp_K + (tmp_K - 1) * (tmp_K - 1));
			
			if (cost >= 0) {
				max_home = max(max_home, cnt_home);
				//cout << "y, x : " << y << ", " << x << '\n';
				//cout << "cost : " << cost << '\n';
				//cout << "home : " << cnt_home << '\n' << '\n';
			}

			tmp_K = cur_K;
		}

		if (map[cur_y][cur_x]) cnt_home++;

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
			if (visited[next_y][next_x]) continue;

			visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
			q.push({ next_y, next_x });
		}
	}

	tmp_K++;

	int cost = cnt_home * M - (tmp_K * tmp_K + (tmp_K - 1) * (tmp_K - 1));

	if (cost >= 0) {
		max_home = max(max_home, cnt_home);
		//cout << "y, x : " << y << ", " << x << '\n';
		//cout << "cost : " << cost << '\n';
		//cout << "home : " << cnt_home << '\n' << '\n';
	}
}

void solve() {
	max_home = 0;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			bfs(y, x);
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[y][x];

		solve();

		cout << "#" << tc << " " << max_home << '\n';
	}

	return 0;
}