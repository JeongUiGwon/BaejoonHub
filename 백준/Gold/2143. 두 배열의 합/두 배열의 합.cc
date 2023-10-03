#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[10005], B[10005];
vector<int> sum_a, sum_b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	long long T, ans = 0;

	cin >> T;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	cin >> m;

	for (int i = 0; i < m; i++)
		cin >> B[i];

	for (int i = 0; i < n; i++)
	{
		int sum = A[i];
		sum_a.push_back(sum);

		for (int j = i + 1; j < n; j++)
		{
			sum += A[j];
			sum_a.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		int sum = B[i];
		sum_b.push_back(sum);

		for (int j = i + 1; j < m; j++)
		{
			sum += B[j];
			sum_b.push_back(sum);
		}
	}

	sort(sum_b.begin(), sum_b.end());

	for (auto item : sum_a)
	{
		int diff = T - item;
		auto ub = upper_bound(sum_b.begin(), sum_b.end(), diff);
		auto lb = lower_bound(sum_b.begin(), sum_b.end(), diff);
		ans += (ub - lb);
	}

	cout << ans;

	return 0;
}