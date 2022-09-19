#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

pair<int, int> coord[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> coord[i].first >> coord[i].second;
    }

    sort(coord, coord + N);

    for (int i = 0; i < N; i++)
    {
        cout << coord[i].first << " " << coord[i].second << '\n';
    }

    return 0;
}