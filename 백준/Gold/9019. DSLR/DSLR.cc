#include <queue>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int A, B;
int visited[10000];

void bfs() {
	queue<pair<int, string>> q;
	q.push({ A, ""});
	visited[A] = 1;

	while (!q.empty())
	{
		int now_num = q.front().first;
		string now_path = q.front().second;
		q.pop();

		if (now_num == B)
		{
			cout << now_path << '\n';
			return;
		}

		int next_num = (now_num * 2) % 10000;

		if (!visited[next_num]) 
		{
			visited[next_num] = 1;
			q.push({ next_num , now_path + "D" });
		}

		next_num = now_num - 1 < 0 ? 9999 : now_num - 1;

		if (!visited[next_num])
		{
			visited[next_num] = 1;
			q.push({ next_num , now_path + "S" });
		}

		next_num = (now_num % 1000) * 10 + (now_num / 1000);

		if (!visited[next_num])
		{
			visited[next_num] = 1;
			q.push({ next_num , now_path + "L" });
		}

		next_num = (now_num % 10) * 1000 + (now_num / 10);

		if (!visited[next_num])
		{
			visited[next_num] = 1;
			q.push({ next_num , now_path + "R" });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		memset(visited, 0, sizeof(visited));

		cin >> A >> B;

		bfs();
	}

	return 0;
}