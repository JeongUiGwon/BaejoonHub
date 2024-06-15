#include <iostream>
#include <algorithm>
#define MAX_N 300000

using namespace std;

typedef long long ll;
ll scovile[MAX_N];
ll MOD = 1000000007;

ll binary_exponentiaion(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	ll sum = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> scovile[i];

	sort(scovile, scovile + N);

	for (int i = 0; i < N; i++) {
		ll max_count = binary_exponentiaion(2, i);
		ll min_count = binary_exponentiaion(2, N - i - 1);
		sum += scovile[i] * (max_count - min_count);
		sum %= MOD;
	}

	cout << sum;

	return 0;
}