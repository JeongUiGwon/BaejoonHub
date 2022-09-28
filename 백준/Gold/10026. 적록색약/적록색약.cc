#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

int N;
int cnt_area_normal = 0;
int cnt_area_blind = 0;
char map[100][100];
int visited[100][100];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x, int type) {
	queue<pair<int, int>> q;
	char color = map[y][x];
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= N) continue;
			if (visited[next_y][next_x] != 0) continue;
			
			if (type == 1 && color != 'B') {
				if (map[next_y][next_x] == 'B') continue;
			}
			else {
				if (map[next_y][next_x] != color) continue;
			}

			visited[next_y][next_x] = 1;
			q.push({ next_y, next_x });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int y = 0; y < N; y++) {
		string colors;
		cin >> colors;

		for (int x = 0; x < N; x++)
			map[y][x] = colors[x];
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 0) {
				cnt_area_normal++;
				bfs(y, x, 0);
			}
		}
	}

	memset(visited, 0, sizeof(visited));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (visited[y][x] == 0) {
				cnt_area_blind++;
				bfs(y, x, 1);
			}
		}
	}

	cout << cnt_area_normal << " " << cnt_area_blind;

	return 0;
}