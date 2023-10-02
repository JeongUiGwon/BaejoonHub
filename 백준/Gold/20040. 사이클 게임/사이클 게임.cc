#include <iostream>

using namespace std;

int parent[500005];

int Find(int a)
{
	if (a == parent[a]) return a;
	else return parent[a] = Find(parent[a]);
}

bool Union(int a, int b)
{
	int pA = Find(a);
	int pB = Find(b);

	if (pA == pB) return true;
	else
	{
		parent[pB] = pA;
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 500005; i++)
		parent[i] = i;

	int n, m;
	int ans = 0;
	cin >> n >> m;

	for (int i = 1; i <= m; i++)
	{
		int a, b;
		cin >> a >> b;

		if (Union(a, b))
		{
			ans = i;
			break;
		}
	}

	cout << ans;

	return 0;
}