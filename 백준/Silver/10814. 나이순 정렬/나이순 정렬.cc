#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

struct PERSON {
    int age;
    string name;
};

bool operator<(PERSON a, PERSON b)
{
    if (a.age < b.age) return true;
    if (a.age > b.age) return false;
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

        people.push_back({ age, name });
    }

    stable_sort(people.begin(), people.end());

    for (int i = 0; i < people.size(); i++)
    {
        cout << people[i].age << " " << people[i].name << '\n';
    }

    return 0;
}