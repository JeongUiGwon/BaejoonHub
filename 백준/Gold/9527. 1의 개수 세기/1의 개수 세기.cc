#include <iostream>
#define MAX 55

using namespace std;

long long A, B;
long long power[MAX];

long long calculate(long long x)
{
	long long ret = x & 1;

	for (int i = MAX - 1; i > 0; i--)
	{
		if (x & (1LL << i))
		{
			ret += power[i - 1] + (x - (1LL << i) + 1);
			x -= 1LL << i;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	power[0] = 1;
	for (long long i = 1; i < 55; i++)
		power[i] = power[i - 1] * 2 + (1LL << i);

	cin >> A >> B;

	long long ans = calculate(B) - calculate(A - 1);
	cout << ans;

	return 0;
}