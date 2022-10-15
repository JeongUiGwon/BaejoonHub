#include <iostream>
#include <vector>
#include <algorithm>
#define INF 213456789
using namespace std;

long A, B, ans;
vector<int> path;

void recur(long num, long cnt) {
	if (num == B) {
		ans = min(ans, cnt);
		return;
	}

	if (num > B) return;

	path.push_back(num);
	recur(num * 2, cnt + 1);
	path.pop_back();

	path.push_back(num);
	recur(num * 10 + 1, cnt + 1);
	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ans = INF;

	cin >> A >> B;

	recur(A, 1);

	if (ans == INF) ans = -1;
	cout << ans;

	return 0;
}