#include <iostream>
#include <algorithm>
#define MAX_N 10

using namespace std;

int n, ans;
int map[MAX_N][MAX_N];
bool is_visited_upward_right[2 * MAX_N];
bool is_visited_downward_right[2 * MAX_N];

void dfs(int diagonal_index, int bishop_cnt) {
	// 우상향의 대각선의 index를 모두 탐색했을 경우,
	if (diagonal_index >= 2 * n - 1) {
		ans = max(ans, bishop_cnt);
		return;
	}

	bool flag = false;

	for (int idx = 0; idx < n - abs(diagonal_index - (n - 1)); idx++) {
		int y = (n - 1 <= diagonal_index) ? n - (idx + 1) : diagonal_index - idx;
		int x = (n - 1 <= diagonal_index) ? diagonal_index - (n - 1) + idx : idx;
		int diagonal_index2 = n - 1 + y - x;

		if (map[y][x] == 1 && !is_visited_upward_right[diagonal_index] && !is_visited_downward_right[diagonal_index2]) {
			flag = true;
			is_visited_upward_right[diagonal_index] = true;
			is_visited_downward_right[diagonal_index2] = true;
			dfs(diagonal_index + 1, bishop_cnt + 1);
			is_visited_upward_right[diagonal_index] = false;
			is_visited_downward_right[diagonal_index2] = false;
		}
	}

	if (!flag)
		dfs(diagonal_index + 1, bishop_cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> map[y][x];

	dfs(0, 0);

	cout << ans;

	return 0;
}