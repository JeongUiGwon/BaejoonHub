#include <iostream>
#include <vector>
#define INF 2134567890;
using namespace std;

int N;
int map[100][100];

void Floyd_Warshall() {
	for (int m = 0; m < N; m++)
		for (int s = 0; s < N; s++)
			for (int e = 0; e < N; e++)
				if (map[s][m] == 1 && map[m][e] == 1)
					map[s][e] = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
		{
			int temp;
			cin >> temp;

			if (temp == 1) map[y][x] = 1;
		}

	Floyd_Warshall();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << map[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}