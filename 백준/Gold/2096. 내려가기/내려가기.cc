#include <iostream>
#define INF 987654321
using namespace std;

int map[100005][3];
int min_table[2][3];
int max_table[2][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int min_val = INF;
			int max_val = 0;

			if (i - 1 >= 0) {
				min_val = min(min_val, min_table[0][j]);
				max_val = max(max_val, max_table[0][j]);

				if (j - 1 >= 0) {
					min_val = min(min_val, min_table[0][j - 1]);
					max_val = max(max_val, max_table[0][j - 1]);
				}

				if (j + 1 < 3) {
					min_val = min(min_val, min_table[0][j + 1]);
					max_val = max(max_val, max_table[0][j + 1]);
				}
			}

			if (min_val == INF) min_val = 0;
			min_table[1][j] = map[i][j] + min_val;
			max_table[1][j] = map[i][j] + max_val;
		}

		for (int j = 0; j < 3; j++) {
			min_table[0][j] = min_table[1][j];
			max_table[0][j] = max_table[1][j];
		}
	}

	int max_ans = 0;
	int min_ans = INF;
	for (int i = 0; i < 3; i++) {
		max_ans = max(max_ans, max_table[1][i]);
		min_ans = min(min_ans, min_table[1][i]);
	}

	cout << max_ans << " " << min_ans;

	return 0;
}