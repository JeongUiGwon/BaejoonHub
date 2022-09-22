#include <iostream>
using namespace std;

typedef long long ll;
int N;

ll table[501];

ll factorial(int val)
{
	if (val == 1) return 1;
	if (table[val] > 0) return table[val];

	return table[val] = factorial(val - 1) * val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int cnt = 0;
	int cnt2 = 0;
	for (int i = 1; i <= N; i++)
	{
		int num = i;
		int num2 = i;
		while (num % 2 == 0)
		{
			num /= 2;
			cnt++;
		}

		while (num % 5 == 0)
		{
			num /= 5;
			cnt2++;
		}
	}

	cout << min(cnt, cnt2);

	return 0;
}