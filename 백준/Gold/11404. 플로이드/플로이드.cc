#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, m;
int graph[101][101];
int dist[100][100];

void init()
{
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			graph[i][j] = INF;
}

void input() 
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;

		if (graph[start][end] > cost)
			graph[start][end] = cost;
	}
}

void floyd_warshall()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dist[i][j] = graph[i][j];

	for (int i = 1; i <= n; i++)
		dist[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF)
				cout << "0 ";
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	init();
	input();
	floyd_warshall();

	return 0;
}