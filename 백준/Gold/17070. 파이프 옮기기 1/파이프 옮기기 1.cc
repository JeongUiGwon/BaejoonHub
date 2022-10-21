#include <iostream>
using namespace std;

struct PIPE {
	int y, x, type;
};

int N, cnt_case;
int map[20][20];

void dfs(PIPE cur) {
	if (cur.y == N && cur.x == N) {
		cnt_case++;
		return;
	}

	if (cur.type == 1) {
		PIPE next = { cur.y, cur.x + 1, 1 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N && map[next.y][next.x] != 1) {
			dfs(next);
		}
		
		next = { cur.y + 1, cur.x + 1, 2 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N) {
			if (map[cur.y + 1][cur.x] != 1 && map[cur.y + 1][cur.x + 1] != 1 && map[cur.y][cur.x + 1] != 1) {
				dfs(next);
			}
		}
	}

	if (cur.type == 2) {
		PIPE next = { cur.y, cur.x + 1, 1 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N && map[next.y][next.x] != 1) {
			dfs(next);
		}

		next = { cur.y + 1, cur.x + 1, 2 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N) {
			if (map[cur.y + 1][cur.x] != 1 && map[cur.y + 1][cur.x + 1] != 1 && map[cur.y][cur.x + 1] != 1) {
				dfs(next);
			}
		}

		next = { cur.y + 1, cur.x, 3 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N) {
			if (map[next.y][next.x] != 1) {
				dfs(next);
			}
		}
	}

	if (cur.type == 3) {
		PIPE next = { cur.y + 1, cur.x + 1, 2 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N) {
			if (map[cur.y + 1][cur.x] != 1 && map[cur.y + 1][cur.x + 1] != 1 && map[cur.y][cur.x + 1] != 1) {
				dfs(next);
			}
		}

		next = { cur.y + 1, cur.x, 3 };
		if (next.y >= 1 && next.y <= N && next.x >= 1 && next.x <= N) {
			if (map[next.y][next.x] != 1) {
				dfs(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cnt_case = 0;

	cin >> N;

	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> map[y][x];

	PIPE start = { 1, 2, 1 };
	dfs(start);

	cout << cnt_case;

	return 0;
}