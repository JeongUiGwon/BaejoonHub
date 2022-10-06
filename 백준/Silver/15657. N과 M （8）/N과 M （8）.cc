#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> inputs;
vector<int> nums;

void permutation(int lv, int idx) {
	if (lv == M) {
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = idx; i < N; i++) {

		nums.push_back(inputs[i]);
		permutation(lv + 1, i);
		nums.pop_back();
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

	permutation(0, 0);

	return 0;
}