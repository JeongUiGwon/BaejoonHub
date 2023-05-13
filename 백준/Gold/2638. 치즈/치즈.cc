#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { -1, 0, 1, 0 };
queue<pair<int, int>> cheeze;

void print_map() {
	cout << "\n-------------MAP-------------\n";

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cout << map[y][x] << " ";
		}
		cout << "\n";
	}
}

void bfs() {
	queue<pair<int,int>> q;

	int visited = map[0][0] + 1;
	map[0][0] = visited;
	q.push({ 0, 0 });

	while (!q.empty()) {
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (map[nextY][nextX] == 1) continue;
			if (map[nextY][nextX] == visited) continue;

			map[nextY][nextX] = visited;
			q.push({ nextY, nextX });
		}
	}
}

void melt_cheeze() {
	int cheeze_count = cheeze.size();

	for (int i = 0; i < cheeze_count; i++) {
		int nowY = cheeze.front().first;
		int nowX = cheeze.front().second;

		cheeze.pop();

		int air_count = 0;

		for (int j = 0; j < 4; j++) {
			int adjacentY = nowY + dy[j];
			int adjacentX = nowX + dx[j];

			if (map[adjacentY][adjacentX] == map[0][0]) air_count++;
		}

		if (air_count >= 2) map[nowY][nowX] = 0;
		else cheeze.push({nowY, nowX});
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
						
			if (map[y][x] == 1)	cheeze.push({y, x});
		}
	}

	map[0][0] = 2;
	int elapsed_time = 0;

	while (!cheeze.empty()) {
		bfs();
		melt_cheeze();
		//print_map();
		elapsed_time++;
	}

	cout << elapsed_time;
}