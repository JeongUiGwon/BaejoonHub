#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int kevin[101];
int score[101];
int visited[101];
vector<int> edges[101];

void init()
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = 0;
		score[i] = 0;
	}
}

int get_score(int now)
{
	int sum = 0;
	queue<pair<int, int>> q;
	visited[now] = 1;
	q.push({ now, 0 });

	while (!q.empty())
	{
		int now_node = q.front().first;
		int now_cnt = q.front().second;
		q.pop();

		for (int i = 0; i < edges[now_node].size(); i++)
		{
			int next = edges[now_node][i];
			
			if (visited[next] == 1) continue;

			visited[next] = 1;
			sum += now_cnt + 1;
			score[next] = now_cnt + 1;
			q.push({ next, now_cnt + 1 });
		}
	}

	kevin[now] = sum;
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	int min_score = 987654321;
	int idx = 0;
	for (int i = 1; i <= N; i++)
	{
		init();

		int score = get_score(i);

		if (score < min_score)
		{
			min_score = score;
			idx = i;
		}
	}

	cout << idx;

	return 0;
}