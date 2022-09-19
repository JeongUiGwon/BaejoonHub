#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

stack<long long> nums;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        long long num;
        cin >> num;

        if (num == 0) nums.pop();
        else nums.push(num);
    }

    long long sum = 0;
    while (!nums.empty())
    {
        long long tmp = nums.top();
        nums.pop();

        sum += tmp;
    }

    cout << sum;

    return 0;
}