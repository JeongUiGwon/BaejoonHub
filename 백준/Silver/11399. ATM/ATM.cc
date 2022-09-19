#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<int> people;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        people.push_back(num);
    }

    sort(people.begin(), people.end());

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += people[i] * (N - i);
    }

    cout << sum;

    return 0;
}