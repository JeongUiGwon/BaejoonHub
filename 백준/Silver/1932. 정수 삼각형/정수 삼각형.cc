#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> tri[500];
vector<int> dp_tri[500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			int val;
			cin >> val;
			tri[i].push_back(val);
		}

		for (int j = 0; j <= i; j++) {
			int prev1 = 0;
			int prev2 = 0;

			if (i > 0) {
				if (j - 1 >= 0) prev1 = dp_tri[i - 1][j - 1];
				if (j < i) prev2 = dp_tri[i - 1][j];
			}
			
			int max_val = max(prev1, prev2);
			int val = max_val + tri[i][j];
			dp_tri[i].push_back(val);
		}
	}

	int max_val = 0;
	for (int i = 0; i < dp_tri[n - 1].size(); i++)
		max_val = max(max_val, dp_tri[n - 1][i]);

	cout << max_val;

	return 0;
}