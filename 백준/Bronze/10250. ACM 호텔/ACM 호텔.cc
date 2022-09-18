#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int H, W, N;
		cin >> H >> W >> N;

		int num = 0;
		int floor = 0;

		for (int i = 1; i <= W; i++)
		{
			if (N <= H * i)
			{
				num = i;
				floor = N % H;

				if (floor == 0) floor = H;

				break;
			}
		}

		cout << floor * 100 + num << '\n';
	}

	return 0;
}