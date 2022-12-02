#include <iostream>
#include <algorithm>
using namespace std;

int N, ans;
int arr[1000];
int table_asc[1000];
int table_dec[1000];
int table_bitonic[1000];

void input() {
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
}

void solve() {
	for (int i = 0; i < N; i++) {
		int max_val = 0;

		for (int j = 0; j < i; j++)
			if (arr[j] < arr[i])
				max_val = max(max_val, table_asc[j]);

		table_asc[i] = max_val + 1;
	}

	for (int i = N - 1; i >= 0; i--) {
		int max_val = 0;

		for (int j = N - 1; j > i; j--)
			if (arr[j] < arr[i])
				max_val = max(max_val, table_dec[j]);

		table_dec[i] = max_val + 1;
	}

	for (int i = 0; i < N; i++) {
		table_bitonic[i] = table_asc[i] + table_dec[i] - 1;
		ans = max(ans, table_bitonic[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();

	cout << ans;

	return 0;
}