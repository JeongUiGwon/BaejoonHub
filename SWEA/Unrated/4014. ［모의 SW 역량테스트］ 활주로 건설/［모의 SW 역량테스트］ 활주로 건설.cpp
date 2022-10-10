#include <iostream>
#include <vector>
using namespace std;

int N, X;
int map[20][20];
vector<int> ans;

void init() {
	ans.clear();
}

void input() {
	cin >> N >> X;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> map[y][x];
}

bool check_horizon(int y) {
	int used[20] = { 0, };
	for (int x = 1; x < N; x++) {
		int prev_H = map[y][x - 1];
		int now_H = map[y][x];
		int gap_H = abs(now_H - prev_H);
		
		if (gap_H > 1) return false;

		if (prev_H < now_H) {
			int tmp = X;
			while (tmp) {
				int idx = x - tmp;

				if (idx < 0) return false;
				if (used[idx]) return false;
				if (map[y][idx] != prev_H) return false;

				used[idx] = 1;
				tmp--;
			}
		}
		else if (now_H < prev_H) {
			int tmp = X;
			while (tmp) {
				int idx = x - 1 + tmp;

				if (idx >= N) return false;
				if (map[y][idx] != now_H) return false;
				
				used[idx] = 1;
				tmp--;
			}
		}
	}
}

bool check_vertical(int x) {
	int used[20] = { 0, };
	for (int y = 1; y < N; y++) {
		int prev_H = map[y - 1][x];
		int now_H = map[y][x];
		int gap_H = abs(now_H - prev_H);

		if (gap_H > 1) return false;

		if (prev_H < now_H) {
			int tmp = X;
			while (tmp) {
				int idx = y - tmp;

				if (idx < 0) return false;
				if (used[idx]) return false;
				if (map[idx][x] != prev_H) return false;

				used[idx] = 1;
				tmp--;
			}
		}
		else if (now_H < prev_H) {
			int tmp = X;
			while (tmp) {
				int idx = y - 1 + tmp;

				if (idx >= N) return false;
				if (map[idx][x] != now_H) return false;

				used[idx] = 1;
				tmp--;
			}
		}
	}
}

void solve() {
	for (int y = 0; y < N; y++)
		if(check_horizon(y)) ans.push_back((y + 1) * 100);

	for (int x = 0; x < N; x++)
		if (check_vertical(x)) ans.push_back(x + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans.size() << "\n";
	}

	return 0;
}