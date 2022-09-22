#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define INF 987654321
using namespace std;

priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int, vector<int>, less<int>> max_pq;
map<int, int> dict;

void init()
{
	while (!min_pq.empty())
	{
		min_pq.pop();
	}

	while (!max_pq.empty())
	{
		max_pq.pop();
	}

	dict.clear();
}

void push(int value)
{
	min_pq.push(value);
	max_pq.push(value);
	dict[value]++;
}

void max_pop()
{
	while (1)
	{
		if (max_pq.empty()) break;

		if (dict[max_pq.top()] > 0)
		{
			dict[max_pq.top()]--;
			max_pq.pop();
			break;
		}
		else
		{
			max_pq.pop();
		}
	}
}

void min_pop()
{
	while (1)
	{
		if (min_pq.empty()) break;

		if (dict[min_pq.top()] > 0)
		{
			dict[min_pq.top()]--;
			min_pq.pop();
			break;
		}
		else
		{
			min_pq.pop();
		}
	}
}

int get_max()
{
	while (1)
	{
		if (max_pq.empty()) return -INF;

		if (dict[max_pq.top()] > 0)
		{
			return max_pq.top();
		}
		else
		{
			max_pq.pop();
		}
	}
}

int get_min()
{
	while (1)
	{
		if (min_pq.empty()) return -INF;

		if (dict[min_pq.top()] > 0)
		{
			return min_pq.top();
		}
		else
		{
			min_pq.pop();
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		init();

		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			char cmd;
			int num;
			cin >> cmd >> num;

			if (cmd == 'I')	push(num);
			else if (cmd == 'D')
			{
				if (num == 1) max_pop();
				else if (num == -1)	min_pop();
			}
		}

		int max_val = get_max();
		int min_val = get_min();

		if (max_val == -INF) cout << "EMPTY\n";
		else cout << max_val << " " << min_val << '\n';
	}

	return 0;
}