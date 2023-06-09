#include <iostream>
#include <string>

using namespace std;

int R, C;
int max_count;
int alphabet_table[26];
char map[20][20];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

void dfs(int y, int x, int count)
{
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
		if (alphabet_table[map[ny][nx] - 'A'] == 1) continue;

		alphabet_table[map[ny][nx] - 'A'] = 1;
		max_count = max(max_count, count + 1);
		dfs(ny, nx, count + 1);

		alphabet_table[map[ny][nx] - 'A'] = 0;
	}
}

int main()
{
	cin >> R >> C;

	for (int y = 0; y < R; y++)
	{
		string input_map;
		cin >> input_map;

		for (int x = 0; x < C; x++)
			map[y][x] = input_map[x];
	}

	alphabet_table[map[0][0] - 'A'] = 1;
	max_count = 1;
	dfs(0, 0, 1);

	cout << max_count;

	return 0;
}