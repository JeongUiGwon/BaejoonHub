#include <iostream>
#include <string>
using namespace std;

int map[64][64];

int is_unify(int cy, int cx, int size)
{
	int flag = 1;
	int type = map[cy][cx];

	for (int y = cy; y < cy + size; y++)
	{
		for (int x = cx; x < cx + size; x++)
		{
			if (type != map[y][x])
			{
				flag = 0;
				break;
			}
		}
		if (!flag) break;
	}

	return flag;
}

void solve(int cy, int cx, int size)
{
	if (is_unify(cy, cx, size))
	{
		cout << map[cy][cx];
	}
	else
	{
		cout << "(";

		for (int y = cy; y < cy + size; y += size / 2)
		{
			for (int x = cx; x < cx + size; x += size / 2)
			{
				solve(y, x, size / 2);
			}
		}

		cout << ")";
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

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

	solve(0, 0, N);

	return 0;
}