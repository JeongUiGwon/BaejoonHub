#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    int S = 0;
    for (int i = 0; i < M; i++)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "add")
        {
            int n;
            cin >> n;
            S |= (1 << n);
        }
        else if (cmd == "remove")
        {
            int n;
            cin >> n;
            S &= ~(1 << n);
        }
        else if (cmd == "check")
        {
            int n;
            cin >> n;
            if (S & (1 << n)) cout << "1\n";
            else cout << "0\n";
        }
        else if (cmd == "toggle")
        {
            int n;
            cin >> n;
            if (S & (1 << n)) S &= ~(1 << n);
            else S |= (1 << n);
        }
        else if (cmd == "all") S = (1 << 21) - 1;
        else if (cmd == "empty") S = 0;
    }

    return 0;
}