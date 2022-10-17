#include <iostream>
using namespace std;

int map[1030][1030];
int table[1030][1030];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	cin >> N >> M;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> map[y][x];

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int val = map[y][x];
			val += table[y][x - 1];
			val += table[y - 1][x];
			val -= table[y - 1][x - 1];

			table[y][x] = val;
		}
	}

	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;

		int val = table[y2][x2];
		val -= table[y2][x1 - 1];
		val -= table[y1 - 1][x2];
		val += table[y1 - 1][x1 - 1];

		cout << val << "\n";
	}

	return 0;
}