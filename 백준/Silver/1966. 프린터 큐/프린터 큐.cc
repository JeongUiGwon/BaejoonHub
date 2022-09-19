#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 0; tc < T; tc++)
    {
        int N, M;
        cin >> N >> M;

        queue<pair<int, int>> q;
        vector<int> prior;
        for (int i = 0; i < N; i++)
        {
            int priority;
            cin >> priority;
            q.push({ i, priority });
            prior.push_back(priority);
        }

        sort(prior.begin(), prior.end(), greater<int>());

        int idx = 0;
        while (!q.empty())
        {
            if (prior[idx] > q.front().second)
            {
                int idx_num = q.front().first;
                int prior_num = q.front().second;
                q.pop();
                q.push({ idx_num, prior_num });
            }
            else
            {
                int idx_num = q.front().first;
                int prior_num = q.front().second;
                q.pop();
                idx++;

                if (idx_num == M) cout << idx << '\n';
            }
        }
    }

    return 0;
}