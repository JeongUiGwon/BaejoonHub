#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> nums;

void permutation(int lv, int num) {
	if (lv == M) {
		for (int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		}
		cout << '\n';

		return;
	}

	for (int i = num + 1; i <= N; i++) {
		nums.push_back(i);
		permutation(lv + 1, i);
		nums.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	permutation(0, 0);

	return 0;
}