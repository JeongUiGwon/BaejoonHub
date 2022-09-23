#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

typedef long long ll;
ll triangles[110];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	triangles[1] = 1;
	triangles[2] = 1;
	triangles[3] = 1;
	triangles[4] = 2;
	triangles[5] = 2;

	for (int i = 6; i <= 100; i++)
	{
		triangles[i] = triangles[i - 1] + triangles[i - 5];
	}

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int N;
		cin >> N;

		cout << triangles[N] << '\n';
	}

	return 0;
}