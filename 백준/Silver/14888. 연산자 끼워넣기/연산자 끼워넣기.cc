#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 11

using namespace std;

int N;
int max_val = -1000000000;
int min_val = 1000000000;
int numbers[MAX_N];
int num_operator[4];
vector<int> order_operator;

int calculate()
{
	int ret = numbers[0];

	for (int i = 0; i < order_operator.size(); i++) {
		int next_num = numbers[1 + i];

		switch (order_operator[i])
		{
		case 0:
			ret += next_num;
			break;
		case 1:
			ret -= next_num;
			break;
		case 2:
			ret *= next_num;
			break;
		case 3:
			ret /= next_num;
			break;
		default:
			break;
		}
	}

	return ret;
}

void dfs(int cur)
{
	if (cur == N - 1) {
		int val = calculate();
		max_val = max(max_val, val);
		min_val = min(min_val, val);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (num_operator[i] == 0) continue;

		order_operator.push_back(i);
		num_operator[i]--;
		dfs(cur + 1);
		order_operator.pop_back();
		num_operator[i]++;
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	for (int i = 0; i < 4; i++)
		cin >> num_operator[i];

	dfs(0);

	cout << max_val << '\n' << min_val;
}