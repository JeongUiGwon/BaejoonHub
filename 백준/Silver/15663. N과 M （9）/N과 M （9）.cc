#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int nums[10];
int visited[10];
vector<int> path;

void input() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> nums[i];
}

void dfs(int lv) {
	if (lv == M) {
		for (int i = 0; i < path.size(); i++)
			cout << path[i] << " ";

		cout << "\n";

		return;
	}

	int prev = 0;
	for (int i = 0; i < N; i++) {
		if (visited[i] || prev == nums[i]) continue;

		prev = nums[i];
		visited[i] = 1;
		path.push_back(nums[i]);
		dfs(lv + 1);
		path.pop_back();
		visited[i] = 0;
	}
}

void solve() {
	sort(nums, nums + N);
	dfs(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	return 0;
}