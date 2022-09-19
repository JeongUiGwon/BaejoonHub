#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

unordered_map<string, int> name_to_num;
vector<string> strangers;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        string str;
        cin >> str;

        name_to_num[str] = 1;
    }

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if (name_to_num[str] == 1)
        {
            strangers.push_back(str);
        }
    }

    cout << strangers.size() << '\n';
    
    sort(strangers.begin(), strangers.end());

    for (int i = 0; i < strangers.size(); i++)
    {
        cout << strangers[i] << '\n';
    }

    return 0;
}