#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct BULK {
    int weight;
    int height;
};

vector<BULK> people;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int weight, height;
        cin >> weight >> height;

        people.push_back({ weight, height });
    }
    
    for (int i = 0; i < people.size(); i++)
    {
        int cnt = 1;

        for (int j = 0; j < people.size(); j++)
        {
            if (people[i].height < people[j].height && people[i].weight < people[j].weight)
            {
                cnt++;
            }
        }

        cout << cnt << " ";
    }

    return 0;
}