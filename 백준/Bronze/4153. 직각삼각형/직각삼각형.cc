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

    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0) break;

        if (a > b && a > c)
        {
            int tmp = a;
            a = c;
            c = tmp;
        }
        else if (b > a && b > c)
        {
            int tmp = b;
            b = c;
            c = tmp;
        }

        if (a * a + b * b == c * c) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    
    return 0;
}