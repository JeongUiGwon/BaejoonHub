#include <iostream>
#include <vector>
#include <cstring>

#define INF 987654321;

using namespace std;

int s[5][5];
vector<int> step;
int dp_table[100001][5][5];

int dp(int cur, int left, int right)
{
	int len = step.size();
	if (cur == len - 1) return 0;
	if ((left != 0 && right != 0) && left == right) return INF;

	int &cache = dp_table[cur][left][right];
	if (cache != -1) return cache;

	return cache = min(dp(cur + 1, step[cur + 1], right) + s[left][step[cur + 1]], dp(cur + 1, left, step[cur + 1]) + s[right][step[cur + 1]]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	step.push_back(0);
	while (true)
	{
		int num;
		cin >> num;

		step.push_back(num);
		if (num == 0) break;
	}

	memset(dp_table, -1, sizeof(dp_table));

	for (int i = 0; i < 5; i++)
		s[i][i] = 1;

	for (int i = 1; i < 5; i++)
		s[0][i] = 2;

	s[1][2] = s[1][4] = s[2][1] = s[2][3] = s[3][2] = s[3][4] = s[4][3] = s[4][1] = 3;
	s[1][3] = s[2][4] = s[3][1] = s[4][2] = 4;

	cout << dp(0, 0, 0);

	return 0;
}