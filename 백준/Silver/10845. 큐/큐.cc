#include <iostream>
#include <string>
#include <queue>
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

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (cmd == "front")
        {
            if (q.size() > 0) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << q.empty() << '\n';
        }
        else if (cmd == "pop")
        {
            if (q.size() > 0)
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "back")
        {
            if (q.size() > 0) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}