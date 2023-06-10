#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	vector<long long> numbers(N);

	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	int left = 0;
	int right = N - 1;
	long long minVal = 3000000000;
	long long val1 = numbers[left];
	long long val2 = numbers[right];

	while (left < right)
	{
		long long temp = numbers[left] + numbers[right];

		if (minVal > abs(temp))
		{
			minVal = abs(temp);
			val1 = numbers[left];
			val2 = numbers[right];
		}

		if (temp < 0) left++;
		else if (temp > 0) right--;
		else break;
	}

	cout << val1 << " " << val2;

	return 0;
}