#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Microbe {
	int y, x, time;
};

// N : 구역 크기, M : 격리시간, K : 미생물 군집의 개수 
int N, M, K, ans;

// 0 : 미생물 군집의 개수 map, 1 : 미생물 방향, 2 : 겹쳤을 경우 덩치가 가장 큰 미생물의 군집 갯수
int map[100][100][3];
int map_temp[100][100][3];
int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };
queue<Microbe> q_microbes;

void init() {
	memset(map, 0, sizeof(map));
	ans = 0;
}

void input() {
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		int y, x, k, dir;
		cin >> y >> x >> k >> dir;
		map[y][x][0] = k;
		map[y][x][1] = dir;
		q_microbes.push({ y, x, 0 });
	}
}

void solve() {
	while (!q_microbes.empty()) {
		int size = q_microbes.size();
		memset(map_temp, 0, sizeof(map_temp));

		// 미생물들 움직이기
		for (int i = 0; i < size; i++) {
			Microbe now = q_microbes.front();
			int k = map[now.y][now.x][0];
			int dir = map[now.y][now.x][1];
			q_microbes.pop();

			// 격리 시간(M)일 때, 더 이상 진행 X
			if (now.time == M) {
				ans += map[now.y][now.x][0];  // 미생물 군집의 개수들 더하기
				continue;
			}

			int next_y = now.y + dy[dir - 1];
			int next_x = now.x + dx[dir - 1];

			// 경계선에 도착했을 경우
			if (next_y == 0 || next_y == N - 1 || next_x == 0 || next_x == N - 1) {
				k /= 2;

				// 없어졌을 경우
				if (k == 0) continue;

				// 방향 전환
				if (dir == 1 || dir == 3) dir++;
				else dir--;
			}

			// 임시 맵에 미생물 정보 기록
			// 겹치지 않을 경우
			if (map_temp[next_y][next_x][0] == 0) {
				map_temp[next_y][next_x][0] = k;
				map_temp[next_y][next_x][1] = dir;
				q_microbes.push({ next_y, next_x, now.time + 1 });
			}
			// 겹칠 경우
			else {
				// 이전 미생물의 갯수를 기록
				if (map_temp[next_y][next_x][2] == 0)
					map_temp[next_y][next_x][2] = map_temp[next_y][next_x][0];

				// 현재 미생물의 갯수가 이전의 미생물의 갯수보다 클 경우
				if (map_temp[next_y][next_x][2] < k) {
					map_temp[next_y][next_x][2] = k;
					map_temp[next_y][next_x][1] = dir;
				}

				// 미생물 갯수 더하기
				map_temp[next_y][next_x][0] += k;
			}
		}

		memcpy(map, map_temp, sizeof(map));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << "\n";
	}

	return 0;
}