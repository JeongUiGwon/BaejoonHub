#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

int dp[1000006];

int get_cnt(int n)
{
    if (dp[n] != 0) return dp[n];

    if (n == 0) return 0;
    else if (n == 1) return 0;
    else
    {
        int a = INF;
        int b = INF;
        int c = INF;

        if (n % 3 == 0)
        {
            a = get_cnt(n / 3) + 1;
        }
        if (n % 2 == 0)
        {
            b = get_cnt(n / 2) + 1;
        }
        c = get_cnt(n - 1) + 1;

        int ret = min(a, b);
        ret = min(ret, c);

        dp[n] = ret;
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X;
    cin >> X;

    cout << get_cnt(X);

    return 0;
}