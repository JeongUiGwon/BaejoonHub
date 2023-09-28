#include <iostream>
#include <algorithm>

using namespace std;

int dp[1003][1003];
string str1, str2;
string str_tmp;

void dfs(int y, int x)
{
	if (dp[y][x] == 0) return;

	if (dp[y][x] == dp[y - 1][x])
		dfs(y - 1, x);
	else if (dp[y][x] == dp[y][x - 1])
		dfs(y, x - 1);
	else
	{
		str_tmp += str1[y - 1];
		dfs(y - 1, x - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> str1 >> str2;

	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	dfs(str1.length(), str2.length());

	string str_ans = "";

	for (int i = str_tmp.length() - 1; i >= 0; i--)
		str_ans += str_tmp[i];

	cout << dp[str1.length()][str2.length()] << "\n";
	cout << str_ans;

	return 0;
}