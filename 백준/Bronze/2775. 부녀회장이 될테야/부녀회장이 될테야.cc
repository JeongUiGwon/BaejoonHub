#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int apart[15][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int y = 0; y < 15; y++)
	{
		for (int x = 1; x < 15; x++)
		{
			if (y == 0)
			{
				apart[y][x] = x;
			}
			else
			{
				int cnt_person = 0;

				for (int i = 1; i <= x; i++)
				{
					cnt_person += apart[y - 1][i];
				}

				apart[y][x] = cnt_person;
			}
		}
	}

	for (int tc = 0; tc < T; tc++)
	{
		int k, n;
		cin >> k >> n;

		cout << apart[k][n] << "\n";
	}

	return 0;
}