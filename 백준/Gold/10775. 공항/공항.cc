#include <iostream>
#define MAX_G 100005

using namespace std;

int G, P;
int g[MAX_G];
int airport[MAX_G];
int parent[MAX_G];

int Find(int a)
{
	int pA = parent[a];

	if (pA == a)
		return a;

	return parent[a] = Find(pA);
}

void Union(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	if (pA <= pB)
		parent[pB] = pA;
	else
		parent[pA] = pB;
}

int main()
{
	// I/O 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	for (int i = 0; i < MAX_G; i++)
		parent[i] = i;

	cin >> G;
	cin >> P;

	for (int i = 1; i <= P; i++) {
		int val;
		cin >> val;

		val = Find(val);

		if (val == 0) break;

		Union(val, val - 1);
		ans++;
	}

	cout << ans;

	return 0;
}