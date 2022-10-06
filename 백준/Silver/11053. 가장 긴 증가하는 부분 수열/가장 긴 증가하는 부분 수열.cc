#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp_table[1003];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int max_val = 0;

	for (int i = 0; i < N; i++) {
		dp_table[i] = 1;

		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j]) {
				dp_table[i] = max(dp_table[i], dp_table[j] + 1);
			}
		}

		max_val = max(max_val, dp_table[i]);
	}

	cout << max_val;

	return 0;
}