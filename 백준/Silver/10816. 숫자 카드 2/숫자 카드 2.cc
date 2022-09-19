#include <iostream>
#include <string>
#include <stack>
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

    unordered_map<int, int> map;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        map[num]++;
    }

    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int num;
        cin >> num;

        cout << map[num] << " ";
    }

    return 0;
}