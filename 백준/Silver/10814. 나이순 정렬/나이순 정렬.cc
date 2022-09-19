#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct PERSON {
    int age, idx;
    string name;
};

bool operator<(PERSON a, PERSON b)
{
    if (a.age < b.age) return true;
    if (a.age > b.age) return false;

    if (a.idx < b.idx) return true;
    if (a.idx > b.idx) return false;
    return false;
}

vector<PERSON> people;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int age;
        string name;
        cin >> age >> name;

        people.push_back({ age, i, name });
    }

    sort(people.begin(), people.end());

    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i].age << " " << people[i].name << '\n';
    }

    return 0;
}