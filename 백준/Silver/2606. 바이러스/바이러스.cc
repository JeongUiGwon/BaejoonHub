#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<int> v[101];
int visited[101];
int cnt_virus = 0;

void dfs(int now)
{
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];

        if (visited[next] == 1) continue;
        visited[next] = 1;
        cnt_virus++;
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    visited[1] = 1;
    dfs(1);

    cout << cnt_virus;
    return 0;
}