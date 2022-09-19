#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        string str;
        cin >> str;

        stack<char> st;
        int flag_no = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                st.push('(');
            }
            else
            {
                if (st.size() == 0)
                {
                    flag_no = 1;
                    break;
                }
                else
                {
                    st.pop();
                }
            }
        }

        if (st.size() != 0)
        {
            flag_no = 1;
        }

        if (flag_no) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}