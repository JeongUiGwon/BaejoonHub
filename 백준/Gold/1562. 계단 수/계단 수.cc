#include <iostream>
#define MOD_NUM 10e8

using namespace std;

long long dp[1 << 10][101][10];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	/*
	* 다이나믹 프로그래밍
	* dp[존재하는 숫자 bit 표시][총 자릿수][마지막 자리의 숫자] = 해당 조건의 경우의 수
	* 
	* ex) 존재하는 숫자 bit 표시
	* 이진수로 표현했을 때, i번째 자릿 수의 값이 1이라면, (i - 1) 숫자가 존재한다는 의미.
	* 502이면, 해당 숫자는 0, 2, 5라는 숫자가 있으므로 0000100101(2) 로 표현된다.
	* 
	*  행 : 마지막 자리의 숫자 / 열 : 총 자릿수 / 값 : 나올 수 있는 경우의 수
	*		1	2	3	4	5	6	7	8	9	10	...	N
	*	0		1	1	...
	*	1	1	1	3	...
	*	2	1	2	3	...
	*	3	1	2	4	...
	*	4	1	2	4	...
	*	5	1	2	4	...
	*	6	1	2	4	...
	*	7	1	2	4	...
	*	8	1	2	3	...
	*	9	1	1	2	...
	*/

	// 한 자릿 수 일때(1 ~ 9), 경우의 수는 1이므로 저장
	for (int i = 1; i <= 9; i++)
		dp[1 << i][1][i] = 1;

	for (int n = 2; n <= N; n++) {	// 자릿 수가 2부터 N까지 탐색
		for (int num = 0; num <= 9; num++) {	// 모든 숫자 (0 ~ 9) 탐색
			for (int bit = 0; bit < (1 << 10); bit++) {	// 모든 bit 경우의 수 탐색
				// 숫자가 0일 때는, 이전 자릿수가 1인 경우에만 다음 수가 0을 올 수 있기 때문에
				// dp[bit 체크][현재 자릿수][현재 숫자] += dp[bit][이전 자릿수][1]
				if (num == 0)
					dp[bit | (1 << num)][n][num] += dp[bit][n - 1][1] % (int)MOD_NUM;

				// 숫자가 9일 때는, 이전 자릿수가 8인 경우에만 다음 수로 9가 올 수 있기 때문에
				// dp[bit 체크][현재 자릿수][현재 숫자] += dp[bit][이전 자릿수][8]
				else if (num == 9)
					dp[bit | (1 << num)][n][num] += dp[bit][n - 1][8] % (int)MOD_NUM;

				// 1 ~ 8 숫자일 경우, 이전 자릿 수가 해당 수의 다음 수이거나 이전 수 일때 해당 수로 올 수 있기 때문에
				// dp[bit 체크][현재 자릿수][현재 숫자] += dp[bit][이전 자릿수][현재 숫자 - 1] + dp[bit][이전 자릿수][현재 숫자 + 1]
				else
					dp[bit | (1 << num)][n][num] += (dp[bit][n - 1][num + 1] + dp[bit][n - 1][num - 1]) % (int)MOD_NUM;
			}
		}
	}

	long long ret = 0;

	// dp[bit가 모두 1로 체크된 상태][자릿 수][마지막 숫자]
	// 마지막 숫자로 올 수 있는 0 ~ 9까지 모든 경우의 수 더하기
	for (int i = 0; i <= 9; i++)
		ret = (ret + dp[(1 << 10) - 1][N][i]) % (int)MOD_NUM;

	cout << ret;

	return 0;
}