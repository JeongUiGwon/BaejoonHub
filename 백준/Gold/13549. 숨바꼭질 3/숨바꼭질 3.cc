#include <iostream>
#include <queue>
using namespace std;

int N, K;
int dp_tb[200005];

void bfs_move(int pos, int cnt) {
	queue<pair<int, int>> q;
	q.push({ N, 0 });

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		if (dp_tb[now.first] >= 0) continue;
		
		dp_tb[now.first] = now.second;

		int val = now.first;
		if (val != 0) {
			while (val < 200000) {
				q.push({ val, now.second });
				val *= 2;
			}
		}

		if (now.first - 1 >= 0)	{
			q.push({ now.first - 1, now.second + 1 });
		}

		if (now.first + 1 <= 100000) {
			q.push({ now.first + 1, now.second + 1});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fill(dp_tb, dp_tb + 200005, -1);

	cin >> N >> K;

	bfs_move(N, 0);

	cout << dp_tb[K];

	return 0;
}