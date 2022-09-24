#include <iostream>
#include <string>
#include <queue>
using namespace std;

int map[101][101];
int visited[101][101];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs() {
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty())
	{
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (map[ny][nx] == 0) continue;
			if (visited[ny][nx] != 0) continue;

			visited[ny][nx] = visited[cy][cx] + 1;
			q.push({ ny, nx });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < M; x++)
		{
			map[y][x] = str[x] - '0';
		}
	}

	bfs();

	cout << visited[N - 1][M - 1];

	return 0;
}