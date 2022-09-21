#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#include <algorithm>
#include <unordered_map>
#define INF 987654321
using namespace std;

int N, r, c;
int ans;

void z_move(int y, int x, int size)
{
	if (y == r && x == c)
	{
		cout << ans << '\n';
		return;
	}

	if (r < y + size && r >= y && c < x + size && c >= x)
	{
		z_move(y, x, size / 2);
		z_move(y, x + size / 2, size / 2);
		z_move(y + size / 2, x, size / 2);
		z_move(y + size / 2, x + size / 2, size / 2);
	}
	else
	{
		ans += size * size;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	z_move(0, 0, (1<<N));

	return 0;
}