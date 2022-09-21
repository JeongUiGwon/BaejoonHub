#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, K;
int table[100005];

int get_take_time(int pos)
{
	queue<pair<int, int>> q;
	q.push({ pos, 0 });
	int ans = 0;
	
	while (!q.empty())
	{
		int now_pos = q.front().first;
		int now_time = q.front().second;
		q.pop();

		if (now_pos == K)
		{
			ans = now_time;
			break;
		}

		int next_pos = now_pos - 1;
		int next_time = now_time + 1;

		if (next_pos >= 0 && table[next_pos] == INF)
		{
			table[next_pos] = next_time;
			q.push({ next_pos, next_time });
		}

		next_pos = now_pos + 1;

		if (next_pos < 100005 && table[next_pos] == INF)
		{
			table[next_pos] = next_time;
			q.push({ next_pos, next_time });
		}

		next_pos = now_pos * 2;

		if (next_pos < 100005 && table[next_pos] == INF)
		{
			table[next_pos] = next_time;
			q.push({ next_pos, next_time });
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 100005; i++)
		table[i] = INF;

	cin >> N >> K;

	table[N] = 0;
	cout << get_take_time(N);

	return 0;
}