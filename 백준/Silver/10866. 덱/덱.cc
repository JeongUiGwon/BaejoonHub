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

    deque<int> dq;
    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push_front")
        {
            int num;
            cin >> num;
            dq.push_front(num);
        }
        else if (cmd == "push_back")
        {
            int num;
            cin >> num;
            dq.push_back(num);
        }
        else if (cmd == "pop_front")
        {
            if (dq.size() > 0)
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "pop_back")
        {
            if (dq.size() > 0)
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front")
        {
            if (dq.size() > 0) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "back")
        {
            if (dq.size() > 0) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }

    return 0;
}