#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int nums[10];
vector<int> path;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> nums[i];
}

void dfs(int lv, int idx) {
	if (lv == M) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";

		cout << "\n";

		return;
	}

	int prev = 0;
	for (int i = idx; i < N; i++) {
		if (prev == nums[i]) continue;

		prev = nums[i];
		path.push_back(nums[i]);
		dfs(lv + 1, i);
		path.pop_back();
	}
}

void solve() {
	sort(nums, nums + N);
	dfs(0, 0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}