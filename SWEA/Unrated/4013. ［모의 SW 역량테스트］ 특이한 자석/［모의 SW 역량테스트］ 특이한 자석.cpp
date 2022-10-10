#include <iostream>
#include <deque>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

deque<int> magnets[4];
vector<pair<int, int>> spin;
int spin_dir[4];

void printMagnet() {
	for (int i = 0; i < 4; i++) {
		cout << "#" << i << " : ";
		for (int j = 0; j < 8; j++) {
			cout << magnets[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void init() {
	for (int i = 0; i < 4; i++) magnets[i].clear();
	spin.clear();
}

void init_solve() {
	memset(spin_dir, 0, sizeof(spin_dir));
}

void input() {
	int K;
	cin >> K;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			int pole;
			cin >> pole;
			magnets[i].push_back(pole);
		}
	}

	for (int i = 0; i < K; i++) {
		int idx, dir;
		cin >> idx >> dir;
		spin.push_back({ idx, dir });
	}
}

void spin_magnet() {
	for (int i = 0; i < 4; i++) {
		int dir = spin_dir[i];

		if (dir == 1) {
			int tmp = magnets[i].back();
			magnets[i].pop_back();
			magnets[i].push_front(tmp);
		}
		else if (dir == -1) {
			int tmp = magnets[i].front();
			magnets[i].pop_front();
			magnets[i].push_back(tmp);
		}
	}
}

void check_spin(int idx, int dir) {
	spin_dir[idx] = dir;

	int next_magnet = idx + 1;
	if (next_magnet < 4 && spin_dir[next_magnet] == 0 && magnets[idx][2] != magnets[next_magnet][6]) {
		check_spin(idx + 1, -dir);
	}

	next_magnet = idx - 1;
	if (next_magnet >= 0 && spin_dir[next_magnet] == 0 && magnets[idx][6] != magnets[next_magnet][2]) {
		check_spin(idx - 1, -dir);
	}
}

void solve() {
	for (int i = 0; i < spin.size(); i++) {
		int idx = spin[i].first - 1;
		int dir = spin[i].second;

		init_solve();
		check_spin(idx, dir);
		spin_magnet();
	}
}

int get_score() {
	int score = 0;
	for (int i = 0; i < 4; i++) {
		score += magnets[i].front() * pow(2, i);
	}
	return score;
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
		cout << "#" << tc << " " << get_score() << "\n";
	}

	return 0;
}