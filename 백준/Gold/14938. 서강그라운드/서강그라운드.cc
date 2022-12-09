#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_item;	// 최대 아이템 갯수
int items[101];	// 각 지역의 아이템 갯수
bool visited[101];
vector<pair<int, int>> graph[101];	// 지역 간의 거리 그래프

void dfs(int area, int range) {
	for (int i = 0; i < graph[area].size(); i++) {
		int dest = graph[area][i].first;
		int dist = graph[area][i].second;

		if (range < dist) continue;
		
		visited[dest] = true;
		dfs(dest, range - dist);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	// n : 지역의 개수, m : 수색범위, r : 길의 개수
	int n, m, r;
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
		cin >> items[i];

	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;

		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}

	// 문제 해결
	for (int i = 1; i <= n; i++) {
		int cnt_item = 0;
		for (int j = 0; j < 101; j++)
			visited[j] = false;

		visited[i] = true;
		dfs(i, m);

		for (int j = 0; j < 101; j++)
			if (visited[j]) cnt_item += items[j];

		max_item = max(max_item, cnt_item);
	}
	
	// 출력
	cout << max_item;

	return 0;
}