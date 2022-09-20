#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int cnt_bfs = 0;
int M, N, K;
int map[60][60];
int visited[60][60];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void bfs(int y, int x)
{
	cnt_bfs++;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	q.push({ y, x });

	while (!q.empty())
	{
		int nowY = q.front().first;
		int nowX = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
			if (visited[nextY][nextX] == 1) continue;
			if (map[nextY][nextX] == 0) continue;

			visited[nextY][nextX] = 1;
			q.push({ nextY, nextX });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cnt_bfs = 0;

		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));

		cin >> M >> N >> K;

		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (map[y][x] == 1 && visited[y][x] == 0)
					bfs(y, x);

		cout << cnt_bfs << '\n';
	}

	return 0;
}