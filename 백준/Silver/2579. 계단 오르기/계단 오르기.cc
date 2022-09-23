#include <iostream>
#include <vector>
using namespace std;

int N;
int ans = -987654321;
vector<int> stairs;
int table[310];
int step1[310];

int dp(int lv)
{
	table[0] = stairs[0];
	table[1] = stairs[0] + stairs[1];
	table[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i <= lv; i++)
	{
		table[i] = max(table[i - 2] + stairs[i], table[i - 3] + stairs[i - 1] + stairs[i]);
	}

	return table[lv];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		stairs.push_back(n);
	}

	cout << dp(N - 1);

	return 0;
}