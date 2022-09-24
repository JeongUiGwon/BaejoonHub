#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[30][30];
int visited[30][30];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
vector<int> cnt_area; 

void bfs(int y, int x)
{
	int cnt = 0;
	queue<pair<int, int>> q;
	visited[y][x] = 1;
	cnt++;
	q.push({ y, x });

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

			visited[ny][nx] = 1;
			cnt++;
			q.push({ ny, nx });
		}
	}

	cnt_area.push_back(cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;

		for (int x = 0; x < N; x++)
		{
			map[y][x] = str[x] - '0';
		}
	}

	for (int y = 0; y < 30; y++) {
		for (int x = 0; x < 30; x++) {
			if (map[y][x] == 0) continue;
			if (visited[y][x] == 1) continue;
			bfs(y, x);
		}
	}

	sort(cnt_area.begin(), cnt_area.end());

	cout << cnt_area.size() << '\n';
	
	for (int i = 0; i < cnt_area.size(); i++)
		cout << cnt_area[i] << '\n';

	return 0;
}