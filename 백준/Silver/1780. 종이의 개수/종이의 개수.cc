#include <iostream>
using namespace std;

int cnt[3];
int map[2200][2200];

int is_unify(int y, int x, int size)
{
	int type = map[y][x];
	int flag = 1;
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (map[i][j] != type)
			{
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}

	if (flag) cnt[type + 1]++;

	return flag;
}

void solve(int y, int x, int size)
{
	if (is_unify(y, x, size)) return;
	else
		for (int i = y; i < y + size; i += size / 3)
			for (int j = x; j < x + size; j += size / 3)
				solve(i, j, size / 3);
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

	solve(0, 0, N);

	for (int i = 0; i < 3; i++)
		cout << cnt[i] << '\n';

	return 0;
}