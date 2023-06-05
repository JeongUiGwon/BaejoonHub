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

	int idx = round(n * 0.15);

	for (int i = idx; i < n - idx; i++)
		res += numbers[i];

	res /= (n - idx * 2);
	res = round(res);

	cout << res;

	return 0;
}