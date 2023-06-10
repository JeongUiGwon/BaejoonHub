#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int parent[10005];
bool is_cycle;
vector<tuple<int, int, int>> graph;

int find_parent(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find_parent(parent[x]);
}

void union_node(int a, int b)
{
	int pa = find_parent(a);
	int pb = find_parent(b);

	if (pa == pb)
	{
		is_cycle = true;
	}
	else
	{
		parent[pb] = pa;
		is_cycle = false;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10005; i++)
		parent[i] = i;

	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		graph.push_back(make_tuple(C, A, B));
	}

	sort(graph.begin(), graph.end());

	long long ans = 0;

	for (int i = 0; i < E; i++)
	{
		union_node(get<1>(graph[i]), get<2>(graph[i]));

		if (!is_cycle) ans += get<0>(graph[i]);
	}

	cout << ans;

	return 0;
}