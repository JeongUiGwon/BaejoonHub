#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int ret = -1;

    int tmp = N / 5;
    int tmp1 = N % 5;

    if (tmp1 == 0)
    {
        ret = tmp;
    }
    if (tmp1 == 1)
    {
        if (N >= 6)
        {
            ret = tmp + 1;
        }
    }
    if (tmp1 == 2)
    {
        if (N >= 12)
        {
            ret = tmp + 2;
        }
    }
    if (tmp1 == 3)
    {
        ret = tmp + 1;
    }
    if (tmp1 == 4)
    {
        if (N >= 9)
        {
            ret = tmp + 2;
        }
    }

    cout << ret;

    return 0;
}