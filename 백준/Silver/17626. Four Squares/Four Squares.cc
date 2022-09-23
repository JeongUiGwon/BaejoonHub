#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;


int main() {
	int n;
	scanf("%d", &n);

	vector<int>dp(n + 1, 0);
	dp[1] = 1;

	for (int i = 2; i <= n; i++) {
		int min_num = INF;

		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			min_num = min(min_num, dp[tmp]);
		}
		dp[i] = min_num + 1;
	}

	printf("%d", dp[n]);

	return 0;
}