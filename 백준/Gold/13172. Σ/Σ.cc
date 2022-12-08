#include <iostream>
#define MOD 1000000007
using namespace std;

long long power(long long n, long long m) {
	long long ret = 1;
	while (m) {
		if (m & 1) ret = ret * n % MOD;
		m = m / 2;
		n = n * n % MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M;
	long long ans = 0;
	cin >> M;

	for (int i = 0; i < M; i++) {
		long long N, S;
		cin >> N >> S;

		ans += (S * (power(N, MOD - 2))) % MOD;
	}

	cout << ans % MOD;

	return 0;
}