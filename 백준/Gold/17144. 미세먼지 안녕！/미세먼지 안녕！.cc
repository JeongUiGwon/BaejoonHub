#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int R, C, T;
int dr[] = { -1, 0, 1, 0 };	// row 방향배열
int dc[] = { 0, 1, 0, -1 };	// col 방향배열
int map[50][50];	// map 정보
vector<pair<int, int>> air_cleaner;	// 공기 청정기 위치

void diffusion() {

	int temp_map[50][50];
	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			temp_map[r][c] = 0;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] == 0) continue;

			if (map[r][c] == -1) {
				temp_map[r][c] = -1;
				continue;
			}

			temp_map[r][c] += map[r][c];
			int diffusion_quantity = map[r][c] / 5;

			for (int i = 0; i < 4; i++) {
				int next_r = r + dr[i];
				int next_c = c + dc[i];

				if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) continue;
				if (map[next_r][next_c] == -1) continue;

				temp_map[next_r][next_c] += diffusion_quantity;
				temp_map[r][c] -= diffusion_quantity;
			}
		}
	}

	for (int r = 0; r < R; r++)
		for (int c = 0; c < C; c++)
			map[r][c] = temp_map[r][c];
}

void circulation() {

	// 공기청정기 윗 공간
	for (int r = air_cleaner[0].first - 1; r > 0; r--)
		map[r][air_cleaner[0].second] = map[r - 1][air_cleaner[0].second];

	for (int c = air_cleaner[0].second; c < C - 1; c++)
		map[0][c] = map[0][c + 1];

	for (int r = 0; r <= air_cleaner[0].first; r++)
		map[r][C - 1] = map[r + 1][C - 1];

	for (int c = C - 1; c > air_cleaner[0].second + 1; c--)
		map[air_cleaner[0].first][c] = map[air_cleaner[0].first][c - 1];

	map[air_cleaner[0].first][air_cleaner[0].second + 1] = 0;

	// 공기청정기 아랫 공간
	for (int r = air_cleaner[1].first + 1; r < R - 1; r++)
		map[r][air_cleaner[1].second] = map[r + 1][air_cleaner[1].second];

	for (int c = air_cleaner[1].second; c < C - 1; c++)
		map[R - 1][c] = map[R - 1][c + 1];

	for (int r = R - 1; r > air_cleaner[1].first; r--)
		map[r][C - 1] = map[r - 1][C - 1];

	for (int c = C - 1; c > air_cleaner[1].second + 1; c--)
		map[air_cleaner[1].first][c] = map[air_cleaner[1].first][c - 1];

	map[air_cleaner[1].first][air_cleaner[1].second + 1] = 0;
}

void printMap() {
	cout << "\n";
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << map[r][c] << " ";
		}
		cout << "\n";
	}
}

int get_dust() {
	int cnt_dust = 0;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] <= 0) continue;
			
			cnt_dust += map[r][c];
		}
	}

	return cnt_dust;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 입력
	cin >> R >> C >> T;

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];

			if (map[r][c] == -1) air_cleaner.push_back({ r, c });
		}
	}

	// 문제 해결
	while (T--) {
		diffusion();
		circulation();
	}

	// 출력
	cout << get_dust();

	return 0;
}