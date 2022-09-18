#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int ret = -INF;
int sum = 0;
int card_cnt = 0;
int N, M;
vector<int> cards;
vector<int> selected;

void dfs(int lv)
{
	if (sum > M) return;
	if (card_cnt == 3)
	{
		ret = max(ret, sum);
		return;
	}

	if (lv == N) return;

	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			sum += cards[lv];
			card_cnt++;
			dfs(lv + 1);
			sum -= cards[lv];
			card_cnt--;
		}
		else
		{
			dfs(lv + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		cards.push_back(num);
	}

	dfs(0);

	cout << ret;

	return 0;
}