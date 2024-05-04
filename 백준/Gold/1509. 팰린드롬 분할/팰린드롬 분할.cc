#include <iostream>
#include <string>
#define MAX_LEN 2501
#define INF 2134567890

using namespace std;

bool dp[MAX_LEN][MAX_LEN];
string str;
int str_len, result[MAX_LEN];

bool is_palindrome(int start, int end) {
	if (end > str_len) 
		return false;

	if (str[start] == str[end] && (dp[start + 1][end - 1] || end - start == 1))
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 문자열 입력
	cin >> str;

	str = " " + str;	
	str_len = str.length();

	// DP 알고리즘
	for (int len = 0; len < str_len; len++) {
		for (int start = 1; start + len < str_len; start++) {
			if (len == 0)
				dp[start][start + len] = true;
			else if (is_palindrome(start, start + len))
				dp[start][start + len] = true;
		}
	}

	result[0] = 0;
	
	for (int end = 1; end < str_len; end++) {
		result[end] = INF;
		for (int start = 1; start <= end; start++) {
			if (dp[start][end] && result[end] > result[start - 1] + 1)
				result[end] = result[start - 1] + 1;
		}
	}

	cout << result[str_len - 1];

	return 0;
}