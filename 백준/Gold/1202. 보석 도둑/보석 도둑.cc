#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX_N 300000
#define MAX_K 300000

using namespace std;

int N, K;
pair<int, int> gems[MAX_N];
int backpack[MAX_K];
priority_queue<int, vector<int>, less<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> gems[i].first >> gems[i].second;

	for (int i = 0; i < K; i++) 
		cin >> backpack[i];

	sort(gems, gems + N);
	sort(backpack, backpack + K);

	int idx = 0;
	long long sum = 0;

	for (int i = 0; i < K; i++) {
		while (idx < N && backpack[i] >= gems[idx].first) {
			pq.push(gems[idx].second);
			idx++;
		}

		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}

	cout << sum;

	return 0;
}