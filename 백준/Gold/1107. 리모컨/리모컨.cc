#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define INF 2134567890
using namespace std;

int broken_table[10];

int check(int num)
{
	int flag = 1;
	string str_num = to_string(num);
	for (int i = 0; i < str_num.length(); i++)
	{
		if (broken_table[str_num[i] - '0'] == 1)
		{
			flag = 0;
			break;
		}
	}

	return flag;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) 
	{
		int num;
		cin >> num;
		broken_table[num] = 1;
	}

	int min_click = abs(N - 100);

	for (int i = 0; i <= 1000000; i++)
	{
		if (check(i))
		{
			int diff = abs(N - i);
			int len = to_string(i).length();
			int cnt_click = diff + len;

			min_click = min(min_click, cnt_click);
		}
	}

	cout << min_click;

	return 0;
}