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


void dfs(int cur, int res)
{
	if (cur == N - 1) {
		max_val = max(max_val, res);
		min_val = min(min_val, res);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (num_operator[i] == 0) continue;

		int next = cur + 1;
		num_operator[i]--;

		if (i == 0)
			dfs(next, res + numbers[next]);
		else if (i == 1)
			dfs(next, res - numbers[next]);
		else if (i == 2)
			dfs(next, res * numbers[next]);
		else if (i == 3)
			dfs(next, res / numbers[next]);

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

	dfs(0, numbers[0]);

	cout << max_val << '\n' << min_val;
}