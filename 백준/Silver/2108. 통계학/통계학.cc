#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

int dat_num[8005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;
    int sum = 0;
    int max_cnt = -INF;
    int max_num = -INF;
    int min_num = INF;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
        sum += num;
        dat_num[num + 4000]++;
        max_cnt = max(max_cnt, dat_num[num + 4000]);
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }

    double avg = (double)sum / N;
    avg = round(avg);

    cout << (int)avg << '\n';

    sort(v.begin(), v.end());

    cout << v[N / 2] << '\n';

    int freq = 0;
    int idx = 0;
    for (int i = 0; i < 8005; i++)
    {
        if (dat_num[i] == max_cnt)
        {
            freq = i - 4000;
            idx++;
        }

        if (idx == 2) break;
    }

    cout << freq << '\n';

    cout << max_num - min_num << '\n';


    return 0;
}