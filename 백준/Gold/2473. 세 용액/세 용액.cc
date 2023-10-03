#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long solutions[5000];
long long ans[3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	long long result = 3000000001;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> solutions[i];

	sort(solutions, solutions + N);

	for (int i = 0; i < N - 2; i++)
	{
		int left = i + 1;
		int right = N - 1;

		while (left < right)
		{
			long long val = solutions[i] + solutions[left] + solutions[right];
			if (abs(val) < result)
			{
				result = abs(val);
				ans[0] = solutions[i];
				ans[1] = solutions[left];
				ans[2] = solutions[right];
			}
			if (val < 0) left++;
			else right--;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << ans[i] << " ";

	return 0;
}