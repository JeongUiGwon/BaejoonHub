#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

int N, M, B;
int map[500][500];

int get_time(int val)
{
    int cnt_dig = 0;
    int cnt_stack = 0;
    int time = 0;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (map[y][x] > val)
            {
                int tmp = map[y][x] - val;
                cnt_dig += tmp;
                time += tmp * 2;
            }
            else if (map[y][x] < val)
            {
                int tmp = val - map[y][x];
                cnt_stack += tmp;
                time += tmp;
            }
        }
    }

    if (cnt_dig + B < cnt_stack) return INF;
    else return time;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    int high_height = -INF;
    int low_height = INF;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> map[y][x];
            high_height = max(high_height, map[y][x]);
            low_height = min(low_height, map[y][x]);
        }
    }   
    
    int min_time = INF;
    int height = 0;
    for (int i = low_height; i <= high_height; i++)
    {
        int time = get_time(i);

        if (min_time >= time)
        {
            min_time = time;
            height = i;
        }
    }

    cout << min_time << " " << height;

    return 0;
}