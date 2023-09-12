#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, ans, max_cost;
int parent[100005];
vector<pair<int, pair<int,int>>> edges;

int Find(int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int Pa = Find(a);
	int Pb = Find(b);

	if (Pa != Pb) parent[Pb] = Pa;
}

vector<pair<int, pair<int, int>>> kruskal()
{
	vector<pair<int, pair<int, int>>> mst;

	for (int i = 0; i < edges.size(); i++)
	{
		pair<int, pair<int, int>> cur_edge = edges[i];

		int start = cur_edge.second.first;
		int end = cur_edge.second.second;
		int cost = cur_edge.first;

		if (Find(start) == Find(end)) continue;

		mst.push_back(cur_edge);
		ans += cost;
		max_cost = max(max_cost, cost);

		Union(start, end);

		if (mst.size() == N - 1) return mst;
	}

	return mst;
}

int main() 
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;

		scanf("%d %d %d", &A, &B, &C);

		edges.push_back({ C, {A, B} });	
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	sort(edges.begin(), edges.end());

	vector<pair<int, pair<int, int>>> mst = kruskal();

	ans -= max_cost;

	printf("%d", ans);

	return 0;
}