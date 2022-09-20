#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int cnt_blue = 0;
int cnt_white = 0;
int map[128][128];

int is_color_unity(int y, int x, int map_size)
{
	int color = map[y][x];
	int flag = 1;
	for (int i = y; i < y + map_size; i++)
	{
		for (int j = x; j < x + map_size; j++)
		{
			if (map[i][j] != color)
			{
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag)
	{
		if (color == 1) cnt_blue++;
		if (color == 0) cnt_white++;
	}

	return flag;
}

void cut_paper(int y, int x, int map_size)
{
	if (is_color_unity(y, x, map_size)) return;

	int half_size = map_size / 2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			cut_paper(y + half_size * i, x + half_size * j, half_size);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];

	cut_paper(0, 0, N);

	cout << cnt_white << '\n';
	cout << cnt_blue;

	return 0;
}