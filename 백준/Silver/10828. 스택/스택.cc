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

    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "push")
        {
            int num;
            cin >> num;
            st.push(num);
        }
        else if (cmd == "top")
        {
            if (st.size() > 0) cout << st.top() << '\n';
            else cout << -1 << '\n';
        }
        else if (cmd == "size")
        {
            cout << st.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << st.empty() << '\n';
        }
        else if (cmd == "pop")
        {
            if (st.size() > 0)
            {
                cout << st.top() << '\n';
                st.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}