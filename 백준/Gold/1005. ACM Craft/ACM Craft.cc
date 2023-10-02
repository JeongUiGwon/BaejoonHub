#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int costs[1003], inDegree[1003], total_cost[1003];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, N, K, X, Y, W;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		vector<int> graph[1003];
		queue<int> q;

		for (int i = 0; i < 1003; i++)
		{
			inDegree[i] = 0;
		}

		cin >> N >> K;

		for (int i = 1; i <= N; i++)
			cin >> costs[i];

		for (int i = 0; i < K; i++)
		{
			cin >> X >> Y;

			graph[X].push_back(Y);
			inDegree[Y]++;
		}
		
		cin >> W;

		for (int i = 1; i <= N; i++)
		{
			if (inDegree[i] == 0) q.push(i);
			total_cost[i] = costs[i];
		}

		while (!q.empty()) 
		{
			int cur = q.front();
			q.pop();

			for (int i = 0; i < graph[cur].size(); i++)
			{
				int next = graph[cur][i];
				inDegree[next]--;
				total_cost[next] = max(total_cost[next], total_cost[cur] + costs[next]);

				if (inDegree[next] == 0)
					q.push(next);
			}
		}

		cout << total_cost[W] << '\n';
	}


	return 0;
}