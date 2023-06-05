#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	double res = 0;

	cin >> n;

	if (n == 0)
	{
		cout << res;
		return 0;
	}

	vector<int> numbers(n);

	for (int i = 0; i < n; i++)
		cin >> numbers[i];

	sort(numbers.begin(), numbers.end());

	double idx = (double)n * 0.15;
	int val = idx;

	if (idx - val >= 0.5) val++;

	int cnt = 0;

	for (int i = val; i < n - val; i++)
	{
		res += numbers[i];
		cnt++;
	}

	res /= (double)(cnt);
	int res2 = res;

	if ((res - res2) >= 0.5) res2++;

	cout << res2;

	return 0;
}