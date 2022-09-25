#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	for (int tc = 0; tc < T; tc++)
	{
		int m, n, x, y, i;
		cin >> m >> n >> x >> y;

		int limit = lcm(m, n);

		for (i = x; i <= limit; i += m)
		{
			int temp = (i % n == 0) ? n : i % n;
			
			if (temp == y) {
				cout << i << '\n';
				break;
			}
		}
		if (i > limit) cout << -1 << '\n';
	}

	return 0;
}