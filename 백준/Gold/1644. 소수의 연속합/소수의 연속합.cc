#include <iostream>
#include <vector>

using namespace std;

bool prime[4000006];
vector<int> prime_num;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 4000006; i++)
		prime[i] = true;

	int N;
	cin >> N;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 2; i * j <= N; j++)
		{
			prime[i * j] = false;
		}
	}
	
	for (int i = 2; i <= N; i++)
	{
		if (prime[i]) prime_num.push_back(i);
	}

	if (N == 1)
	{
		cout << 0;
		return 0;
	}

	int left = 0;
	int right = 0;
	int val = prime_num[0];
	int ans = 0;

	while (left <= right)
	{
		if (val < N)
		{
			right++;
			if (right >= prime_num.size()) break;
			val += prime_num[right];
		}
		else if (val > N)
		{
			val -= prime_num[left];
			left++;
		}
		else
		{
			ans++;
			right++;
			if (right >= prime_num.size()) break;
			val += prime_num[right];
		}
	}

	cout << ans;

	return 0;
}