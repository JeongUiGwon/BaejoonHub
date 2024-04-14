#include <iostream>
#include <queue>
#include <string>
#include <set>
#define MAX_N 1000
#define MAX_M 1000

using namespace std;

int N, M;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = { 0, 1, 0, -1 };
int group[MAX_N * MAX_M];
int map[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];
int ans[MAX_N][MAX_M];

void bfs(int y, int x, int group_idx)
{
	int ret = 1;
	queue<pair<int,int>> q;
	q.push({ y, x });
	map[y][x] = group_idx;
	visited[y][x] = 1;

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = cur_y + dy[i];
			int next_x = cur_x + dx[i];

			if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
			if (map[next_y][next_x] != 0) continue;
			if (visited[next_y][next_x]) continue;

			ret++;
			map[next_y][next_x] = group_idx;
			q.push({ next_y, next_x });
			visited[next_y][next_x] = 1;
		}
	}

	group[group_idx] = ret % 10;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		string row;
		cin >> row;

		for (int x = 0; x < M; x++) {
			map[y][x] = row[x] - '0';
		}
	}

	int group_idx = 2;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] != 0) continue;

			bfs(y, x, group_idx++);
		}
	}

	set<int> groups;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] != 1) continue;

			groups.clear();

			for (int i = 0; i < 4; i++) {
				int next_y = y + dy[i];
				int next_x = x + dx[i];

				if (next_y < 0 || next_y >= N || next_x < 0 || next_x >= M) continue;
				if (map[next_y][next_x] == 1) continue;

				int group_idx = map[next_y][next_x];
				groups.insert(group_idx);
			}

			int cnt = 1;
			set<int>::iterator iter;
			for (iter = groups.begin(); iter != groups.end(); iter++)
				cnt += group[*iter];

			ans[y][x] = cnt % 10;
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			cout << ans[y][x];
		
		cout << '\n';
	}

	return 0;
}