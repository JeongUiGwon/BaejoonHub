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

    int A, B, V;
    cin >> A >> B >> V;

    int day = 0;
    int pos = 0;
    int day_up = A - B;

    int tmp = (V - A) / day_up;

    if ((V - A) % day_up != 0) tmp++;

    tmp++;
    
    cout << tmp;
    
    return 0;
}