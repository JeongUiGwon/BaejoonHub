#include <iostream>
#include <tuple>
#include <queue>
using namespace std;

int M, N, H;
int cnt_day = 0;
int map[100][100][100];
int dz[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};
int dx[] = {0, 0, 0, 0, 1, -1};

void bfs()
{
	queue<tuple<int, int, int>> q;

	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (map[z][y][x] == 1) q.push(make_tuple(z, y, x));

	while (!q.empty())
	{
		int cur_z = get<0>(q.front());
		int cur_y = get<1>(q.front());
		int cur_x = get<2>(q.front());
		cnt_day = map[cur_z][cur_y][cur_x];
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int next_z = cur_z + dz[i];
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_z < 0 || next_z >= H || next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
			if (map[next_z][next_y][next_x] != 0) continue;

			map[next_z][next_y][next_x] = map[cur_z][cur_y][cur_x] + 1;
			q.push(make_tuple(next_z, next_y, next_x));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N >> H;

	for (int z = 0; z < H; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> map[z][y][x];

	bfs();

	int flag_fail = 0;
	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (map[z][y][x] == 0)
				{
					flag_fail = 1;
					break;
				}
			}
			if (flag_fail) break;
		}
		if (flag_fail) break;
	}

	if (flag_fail) cout << -1;
	else cout << cnt_day - 1;

	return 0;
}