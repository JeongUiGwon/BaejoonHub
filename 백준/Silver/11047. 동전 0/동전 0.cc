#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> coins;
	for (int i = 0; i < N; i++)
	{
		int coin;
		cin >> coin;
		coins.push_back(coin);
	}

	int idx = N - 1;
	int cnt_coin = 0;
	while (K > 0)
	{
		if (K / coins[idx] == 0)
		{
			idx--;
		}
		else
		{
			cnt_coin += K / coins[idx];
			K %= coins[idx];
		}
	}

	cout << cnt_coin;

	return 0;
}