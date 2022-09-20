#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long x;
		cin >> x;

		if (x == 0)
		{
			if (pq.size() == 0) cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}