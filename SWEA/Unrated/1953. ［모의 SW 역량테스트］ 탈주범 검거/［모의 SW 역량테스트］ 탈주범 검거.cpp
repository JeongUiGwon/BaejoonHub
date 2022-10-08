#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int N, M, R, C, L;
int map[50][50];
int visited[50][50];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

void pipe_inlet(int type, int dir[]) {

	if (type == 1) {
		for (int i = 0; i < 4; i++) dir[i] = 1;
	}
	else if (type == 2) {
		dir[0] = 1;
		dir[2] = 1;
	}
	else if (type == 3) {
		dir[1] = 1;
		dir[3] = 1;
	}
	else if (type == 4) {
		dir[0] = 1;
		dir[1] = 1;
	}
	else if (type == 5) {
		dir[1] = 1;
		dir[2] = 1;
	}
	else if (type == 6) {
		dir[2] = 1;
		dir[3] = 1;
	}
	else if (type == 7) {
		dir[3] = 1;
		dir[0] = 1;
	}
}

bool can_move(int y, int x, int dir) {
	int nextY = y + dy[dir];
	int nextX = x + dx[dir];

	if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) return false;

	int next_type = map[nextY][nextX];
	int check_dir = dir + 2 >= 4 ? dir - 2 : dir + 2;

	int dir_arr[4] = { 0, };
	pipe_inlet(next_type, dir_arr);

	if (dir_arr[check_dir]) return true;
	else return false;
}

vector<int> find_dir(int y, int x) {
	int dir[4] = {0, };
	vector<int> ans;
	int type = map[y][x];

	pipe_inlet(type, dir);

	for (int i = 0; i < 4; i++) {
		if (dir[i] == 0) continue;
		if (can_move(y, x, i)) ans.push_back(i);
	}
	
	return ans;
}

void bfs() {
	queue<pair<int, int>> q;
	visited[R][C] = 1;
	q.push({ R, C });

	while (!q.empty()) {
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		q.pop();

		if (visited[cur_y][cur_x] == L) continue;

		vector<int> dir_vect = find_dir(cur_y, cur_x);

		for (int i = 0; i < dir_vect.size(); i++) {
			int next_y = cur_y + dy[dir_vect[i]];
			int next_x = cur_x + dx[dir_vect[i]];

			if (visited[next_y][next_x]) continue;

			visited[next_y][next_x] = visited[cur_y][cur_x] + 1;
			q.push({next_y, next_x});
		}
	}
}

int get_fugitive() {
	int cnt = 0;

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (visited[y][x] > 0) cnt++;

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// T : test case
	int T;
	cin >> T;

	// tc : test case num
	for (int tc = 1; tc <= T; tc++) {
		
		//init
		memset(visited, 0, sizeof(visited));

		// N : vertical size, M : horizontal size, R : vertical position, C : horizontal position, L : time
		cin >> N >> M >> R >> C >> L;

		// input map
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				cin >> map[y][x];

		bfs();

		cout << "#" << tc << " " << get_fugitive() << "\n";
	}

	return 0;
}
