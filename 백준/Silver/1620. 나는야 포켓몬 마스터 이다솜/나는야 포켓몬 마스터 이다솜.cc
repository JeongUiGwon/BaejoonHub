#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

unordered_map<int, string> num_to_name;
unordered_map<string, int> name_to_num;

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

        num_to_name[i] = str;
        name_to_num[str] = i;
    }

    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str;

        if (str[0] >= '0' && str[0] <= '9')
        {
            cout << num_to_name[stoi(str)] << '\n';
        }
        else
        {
            cout << name_to_num[str] << '\n';
        }
    }

    return 0;
}