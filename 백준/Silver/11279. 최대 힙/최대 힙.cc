#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#define INF 987654321
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	priority_queue<long long> pq;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;

		if (n == 0)
		{
			if (pq.size() == 0) cout << 0 << '\n';
			else
			{
				int tmp = pq.top();
				cout << tmp << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(n);
		}
	}

	return 0;
}