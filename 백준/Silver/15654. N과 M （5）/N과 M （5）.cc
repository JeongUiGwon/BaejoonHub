#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int visited[10];
vector<int> inputs;
vector<int> nums;

void permutation(int lv) {
	if (lv == M) {
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = 0; i < N; i++) {

		if (visited[i]) continue;

		visited[i] = 1;
		nums.push_back(inputs[i]);
		permutation(lv + 1);
		nums.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		inputs.push_back(n);
	}

	sort(inputs.begin(), inputs.end());

	permutation(0);

	return 0;
}