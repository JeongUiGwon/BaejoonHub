#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

long long N, M;
vector<long long> woods;

long long get_height(long long val)
{
    long long sum_height = 0;
    for (int i = 0; i < woods.size(); i++)
    {
        if (woods[i] - val <= 0) continue;
        sum_height += woods[i] - val;
    }

    return sum_height;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    long long max_height = 0;
    for (int i = 0; i < N; i++)
    {
        long long height;
        cin >> height;

        max_height = max(max_height, height);
        woods.push_back(height);
    }

    long long start = 0;
    long long end = max_height;
    long long mid;
    long long ret = -1;

    while (start <= end)
    {
        mid = (start + end) / 2;
        long long sum_height = get_height(mid);

        if (sum_height >= M)
        {
            ret = mid;
            start = mid + 1;
        }
        else
            end = mid - 1;
    }

    cout << ret;

    return 0;
}