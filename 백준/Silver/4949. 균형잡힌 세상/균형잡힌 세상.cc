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

    while (1)
    {
        string s;
        getline(cin, s);

        if (s == ".") break;

        stack<char> st;
        int flag_no = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
                st.push('[');

            if (s[i] == '{')
                st.push('{');

            if (s[i] == '(')
                st.push('(');

            if (s[i] == ']')
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    flag_no = 1;
                    break;
                }
            }

            if (s[i] == '}')
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    flag_no = 1;
                    break;
                }
            }

            if (s[i] == ')')
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    flag_no = 1;
                    break;
                }
            }
        }

        if (flag_no || !st.empty()) cout << "no" << '\n';
        else cout << "yes" << '\n';
    }    

    return 0;
}