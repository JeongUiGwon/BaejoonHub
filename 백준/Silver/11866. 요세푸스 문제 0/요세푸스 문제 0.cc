#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);

    cout << "<";

    int idx = 0;
    while (!q.empty())
    {
        for (int i = 1; i < K; i++)
        {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }

        idx++;
        cout << q.front();

        if (idx != N) cout << ", ";
        q.pop();
    }

    cout << ">";

    return 0;
}