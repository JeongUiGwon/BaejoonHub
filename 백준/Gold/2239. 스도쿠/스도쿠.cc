#include <stdio.h>
#include <vector>

using namespace std;

int map[9][9], unsolved_block_cnt;
bool is_end = false;
vector<pair<int, int>> unsolved_block;

int check_horizontal(int y, int val)
{
	for (int x = 0; x < 9; x++) 
		if (map[y][x] == val) return 1;

	return 0;
}

int check_vertical(int x, int val)
{
	for (int y = 0; y < 9; y++)
		if (map[y][x] == val) return 1;

	return 0;
}

int check_square(int y, int x, int val)
{
	int square_y = y / 3;
	int square_x = x / 3;

	for (int my = 3 * square_y; my < 3 * (square_y + 1); my++)
		for (int mx = 3 * square_x; mx < 3 * (square_x + 1); mx++)
			if (map[my][mx] == val) return 1;

	return 0;
}

void print_map()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			printf("%d", map[y][x]);
		}
		printf("\n");
	}
}

void dfs(int cur)
{
	if (is_end) return;

	if (cur == unsolved_block_cnt)
	{
		print_map();
		is_end = true;
		return;
	}

	int cur_y = unsolved_block[cur].first;
	int cur_x = unsolved_block[cur].second;

	for (int i = 1; i <= 9; i++)
	{
		if (check_horizontal(cur_y, i)) continue;
		if (check_vertical(cur_x, i)) continue;
		if (check_square(cur_y, cur_x, i)) continue;

		map[cur_y][cur_x] = i;
		dfs(cur + 1);
		map[cur_y][cur_x] = 0;
	}
}

int main()
{
	for (int y = 0; y < 9; y++)
	{
		char str[10];
		scanf("%s", str);

		for (int x = 0; x < 9; x++)
		{
			int tmp_num = str[x] - '0';
			map[y][x] = tmp_num;
			if (tmp_num == 0) unsolved_block.push_back({ y, x });
		}
	}

	unsolved_block_cnt = unsolved_block.size();

	dfs(0);

	return 0;
}