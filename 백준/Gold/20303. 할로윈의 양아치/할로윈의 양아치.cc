#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;
int candy[30001];
int total_candy[30001];
int root[30001];
vector<int> group;
vector<int> friends[30001];
int dp[30004][3003];

int Find(int a)
{
	if (root[a] == a)
		return a;

	return root[a] = Find(root[a]);
}

void Union(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	if (pA <= pB)
		root[pB] = pA;
	else
		root[pA] = pB;
}

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	// 초기화
	for (int i = 0; i < 30001; i++)
		root[i] = i;

	// N : 거리의 있는 아이의 수, M : 아이들의 친구 관계 수, K : 울음소리가 공명하기 위한 최소 아이의 수
	cin >> N >> M >> K;

	// 아이들이 받은 사탕의 수 입력
	for (int i = 1; i <= N; i++)
		cin >> candy[i];


	// 친구 관계 입력
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		Union(a, b);
	}
	
	for (int a = 1; a <= N; a++) {
		int pA = Find(a);
		friends[pA].push_back(a);
		group.push_back(pA);
	}

	sort(group.begin(), group.end());
	group.erase(unique(group.begin(), group.end()), group.end());

	for (int i = 0; i < group.size(); i++) {
		int rep = group[i];
		for (int j = 0; j < friends[rep].size(); j++)
			total_candy[i] += candy[friends[rep][j]];
	}

	int ans = 0;

	for (int i = 0; i < group.size(); i++) {
		int friend_cnt = friends[group[i]].size();
		for (int j = K - 1; j >= 0; j--) {
			if (j - friend_cnt >= 0)
				dp[i + 1][j] = max(dp[i][j], dp[i][j - friend_cnt] + total_candy[i]);
			else
				dp[i + 1][j] = dp[i][j];	

			ans = max(ans, dp[i + 1][j]);
		}
	}

	cout << ans << '\n';

	return 0;
}