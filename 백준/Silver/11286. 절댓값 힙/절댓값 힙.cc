#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

struct compare {
	bool operator()(long long a, long long b) {
		if (abs(a) < abs(b)) return false;
		if (abs(a) > abs(b)) return true;

		if (a < b) return false;
		if (a > b) return true;
		return false;
	}
};

priority_queue<long long, vector<long long>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<int> ans;

	for (int i = 0; i < N; i++) {
		long long x;
		cin >> x;
		
		if (x == 0) {
			if (pq.empty())
			{
				ans.push_back(0);
				continue;
			}
			long long tmp = pq.top();
			ans.push_back(tmp);
			pq.pop();
		}
		else pq.push(x);
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}

	return 0;
}