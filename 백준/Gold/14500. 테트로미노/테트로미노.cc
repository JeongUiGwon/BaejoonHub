#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int N, M;
int max_score = 0;
int map[500][500];
int visited[500][500];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

int get_shape_score(int y, int x, int dir) {
	int score = map[y][x];

	for (int i = 0; i < 3; i++) {
		int next_dir = dir + i;
		if (next_dir >= 4) next_dir -= 4;

		int nextY = y + dy[next_dir];
		int nextX = x + dx[next_dir];

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) return 0;

		score += map[nextY][nextX];
	}

	return score;
}

void shape(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int score = get_shape_score(y, x, i);
		max_score = max(max_score, score);
	}
}

void dfs(int lv, int y, int x, int score) {
	if (lv == 3) {
		max_score = max(max_score, score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
		if (visited[nextY][nextX] == 1) continue;

		visited[nextY][nextX] = 1;
		dfs(lv + 1, nextY, nextX, score + map[nextY][nextX]);
		visited[nextY][nextX] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> map[y][x];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			visited[y][x] = 1;
			dfs(0, y, x, map[y][x]);
			visited[y][x] = 0;
			shape(y, x);
		}
	}

	cout << max_score;

	return 0;
}