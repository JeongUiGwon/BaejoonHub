#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#define INF 987654321

using namespace std;

int N, M;
int map[1003][1003];
int visited1[1003][1003];
int visited2[1003][1003];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int min_dist = INF;

struct Node {
	int y, x, cnt;
};

void bfs() {

	queue<Node> q;

	q.push({ 0, 0, 0 });
	visited1[0][0] = 1;
	//visited2[0][0] = 1;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Node next = { now.y + dy[i], now.x + dx[i], now.cnt };

			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;

			if (now.cnt == 1) {
				if (map[next.y][next.x] == 1) continue;

				if (visited1[next.y][next.x] != 0 || visited2[next.y][next.x] != 0) continue;

				visited2[next.y][next.x] = visited2[now.y][now.x] + 1;
				q.push(next);
			}
			else {
				if (visited1[next.y][next.x] != 0) continue;

				if (map[next.y][next.x] == 0) {
					visited1[next.y][next.x] = visited1[now.y][now.x] + 1;
					q.push(next);
				}
				else {
					visited2[next.y][next.x] = visited1[now.y][now.x] + 1;
					next.cnt = 1;
					q.push(next);
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		string map_row;
		cin >> map_row;

		for (int x = 0; x < M; x++)
			map[y][x] = map_row[x] - '0';
	}
	
	bfs();

	int dist1 = visited1[N - 1][M - 1];
	int dist2 = visited2[N - 1][M - 1];

	if (dist1 == 0) dist1 = INF;
	if (dist2 == 0) dist2 = INF;

	min_dist = min(min_dist, dist1);
	min_dist = min(min_dist, dist2);

	if (min_dist == INF) min_dist = -1;

	cout << min_dist;

	return 0;
}