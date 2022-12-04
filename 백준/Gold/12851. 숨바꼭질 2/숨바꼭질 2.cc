#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

int dist[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// init
	for (int i = 0; i < 100005; i++)
		dist[i] = INF;

	//input
	int N, K;
	cin >> N >> K;

	int case_cnt = 0;
	dist[N] = 0;
	queue<int> q;
	q.push(N);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == K) {
			case_cnt++;
			continue;
		}

		if (now + 1 <= 100000) {
			if (dist[now + 1] >= dist[now] + 1) {
				dist[now + 1] = dist[now] + 1;
				q.push(now + 1);
			}
		}

		if (now - 1 >= 0) {
			if (dist[now - 1] >= dist[now] + 1) {
				dist[now - 1] = dist[now] + 1;
				q.push(now - 1);
			}
		}

		if (now * 2 <= 200000) {
			if (dist[now * 2] >= dist[now] + 1) {
				dist[now * 2] = dist[now] + 1;
				q.push(now * 2);
			}
		}
	}

	cout << dist[K] << "\n";
	cout << case_cnt;

	return 0;
}