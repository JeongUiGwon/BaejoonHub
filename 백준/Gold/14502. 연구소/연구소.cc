#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, max_safetyArea = 0;
int map[10][10];
int tmp_map[10][10];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<pair<int, int>> virus;
vector<pair<int, int>> walls;

void bfs() {
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			tmp_map[y][x] = map[y][x];

	queue<pair<int, int>> q;
	for (int i = 0; i < virus.size(); i++)
		q.push({ virus[i].first, virus[i].second });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
			if (tmp_map[next_y][next_x] != 0) continue;

			tmp_map[next_y][next_x] = 2;
			q.push({ next_y, next_x });
		}
	}
}

int get_safetyArea() {
	int ret = 0;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (tmp_map[y][x] == 0) ret++;

	return ret;
}

void dfs(int lv) {
	if (lv == 3) {
		bfs();
		int safetyArea = get_safetyArea();
		max_safetyArea = max(max_safetyArea, safetyArea);
		return;
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] != 0) continue;

			map[y][x] = 1;
			dfs(lv + 1);
			map[y][x] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++)	{
		for (int x = 0; x < M; x++)	{
			cin >> map[y][x];
			if (map[y][x] == 2) virus.push_back({ y, x });
		}
	}

	dfs(0);

	cout << max_safetyArea;

	return 0;
}