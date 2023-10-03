#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visited[32001];
int inDegree[32001];
vector<int> graph[32001];
vector<int> v_nums;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		inDegree[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		queue<int> q;

		if (!inDegree[i] && !visited[i])
		{
			visited[i] = 1;
			q.push(i);
			v_nums.push_back(i);

			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				for (int j = 0; j < graph[cur].size(); j++)
				{
					int next = graph[cur][j];

					if (!visited[next] && --inDegree[next] == 0)
					{
						visited[next] = 1;
						q.push(next);
						v_nums.push_back(next);
					}
				}
			}
		}
	}

	for (auto item : v_nums)
	{
		cout << item << " ";
	}

	return 0;
}