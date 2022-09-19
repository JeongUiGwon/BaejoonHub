#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

int dat_cnt0[50];
int dat_cnt1[50];
int cnt_0 = 0;
int cnt_1 = 0;

pair<int,int> fibonacci(int n) {
    if (dat_cnt0[n] != 0 && dat_cnt1[n] != 0)
        return { dat_cnt0[n], dat_cnt1[n] };

    if (n == 0) {
        dat_cnt0[n] = 1;
        dat_cnt1[n] = 0;
        return {1, 0};
    }
    else if (n == 1) {
        dat_cnt0[n] = 0;
        dat_cnt1[n] = 1;
        return { 0, 1};
    }
    else {
        pair<int, int> a = fibonacci(n - 1);
        pair<int, int> b = fibonacci(n - 2);
        dat_cnt0[n] = a.first + b.first;
        dat_cnt1[n] = a.second + b.second;
        return { dat_cnt0[n], dat_cnt1[n] };
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        int n;
        cin >> n;

        pair<int, int> ret = fibonacci(n);

        cout << ret.first << " " << ret.second << '\n';
    }

    return 0;
}