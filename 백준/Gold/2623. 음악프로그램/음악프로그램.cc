#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int arr[1001];
int inDegree[1001];
int visited[1001];
vector<int> graph[1001];
vector<int> singers;

bool is_cycle()
{
	for (int i = 1; i <= N; i++)
		if (!visited[i]) return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
			cin >> arr[j];

		for (int j = 1; j < n; j++)
		{
			graph[arr[j - 1]].push_back(arr[j]);
			inDegree[arr[j]]++;
		}
	}

	queue<int> q;

	for (int i = 1; i <= N; i++)
	{
		if (!visited[i] && inDegree[i] == 0)
		{
			singers.push_back(i);
			visited[i] = 1;
			q.push(i);
			
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				for (int j = 0; j < graph[cur].size(); j++)
				{
					int next = graph[cur][j];

					if (--inDegree[next] != 0 || visited[next]) continue;

					singers.push_back(next);
					visited[next] = 1;
					q.push(next);
				}
			}
		}
	}

	if (is_cycle()) 
		cout << "0";
	else
	{
		for (int i = 0; i < singers.size(); i++)
			cout << singers[i] << "\n";
	}


	return 0;
}