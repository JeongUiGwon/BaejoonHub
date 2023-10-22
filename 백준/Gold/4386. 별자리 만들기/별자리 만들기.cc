#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <algorithm>

using namespace std;

int n, parent[101];
vector<pair<float, float>> stars;
vector<tuple<float, int, int>> graph;

int Find(int x)
{
	return parent[x] == x ? x : parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	parent[pB] = pA;
}

bool is_cycle(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB)
		return true;

	return false;
}

float get_dist(pair<float, float> a, pair<float, float> b)
{
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	float ans = 0;

	for (int i = 0; i < 101; i++)
		parent[i] = i;

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		float x, y;
		cin >> x >> y;
		stars.push_back({ x, y });
	}

	for (int i = 0; i < stars.size(); i++)
	{
		for (int j = 0; j < stars.size(); j++)
		{
			if (i == j) continue;

			float dist = get_dist(stars[i], stars[j]);
			graph.push_back(make_tuple(dist, i, j));
		}
	}

	sort(graph.begin(), graph.end());

	for (int i = 0; i < graph.size(); i++)
	{
		float dist = get<0>(graph[i]);
		int start = get<1>(graph[i]);
		int end = get<2>(graph[i]);

		if (!is_cycle(start, end))
		{
			Union(start, end);
			ans += dist;
		}
	}

	cout << ans;

	return 0;
}