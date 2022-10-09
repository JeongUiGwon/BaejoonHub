#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

struct PersonInfo {
	int y, x, moveTime, startTime, endTime, finish;
};

struct StairInfo {
	int y, x, len, usrNum;
};

int N;
int min_time;
int map[10][10];
vector<PersonInfo> people;
vector<StairInfo> stairs;
vector<int> path;
queue<int> waiting_line[2];

void init() {
	people.clear();
	stairs.clear();
	path.clear();
	min_time = INF;
}

void init_sim() {
	for (int i = 0; i < people.size(); i++) {
		people[i].moveTime = -1;
		people[i].startTime = -1;
		people[i].endTime = -1;
		people[i].finish = 0;
	}

	for (int i = 0; i < stairs.size(); i++) {
		stairs[i].usrNum = 0;
	}

	for (int i = 0; i < 2; i++) {
		while (!waiting_line[i].empty()) {
			waiting_line[i].pop();
		}
	}
}

void input() {
	cin >> N;

	for (int y = 0; y < N; y++)	{
		for (int x = 0; x < N; x++)	{
			cin >> map[y][x];

			if (map[y][x] == 1) people.push_back({ y, x, -1, -1, -1, 0 });
			if (map[y][x] > 1) stairs.push_back({ y, x, map[y][x], 0 });
		}
	}
}

void cal_dist() {
	for (int i = 0; i < people.size(); i++) {
		PersonInfo person = people[i];
		int idx = path[i];
		StairInfo stair = stairs[idx];

		int dist = abs(person.y - stair.y) + abs(person.x - stair.x);

		people[i].moveTime = dist;
	}
}

void goToStair(int time) {
	for (int i = 0; i < people.size(); i++) {
		PersonInfo person = people[i];
		int idx = path[i];

		if (person.moveTime == time) {
			waiting_line[idx].push(i);
		}
	}
}

void goingDown(int time) {
	for (int i = 0; i < stairs.size(); i++) {
		int stair_usr = stairs[i].usrNum;
		int waiting_usr = waiting_line[i].size();

		if (stair_usr == 3 && waiting_usr == 0) continue;

		while (!waiting_line[i].empty()) {
			if (stairs[i].usrNum == 3) break;

			int person_idx = waiting_line[i].front();
			waiting_line[i].pop();

			people[person_idx].startTime = time;
			people[person_idx].endTime = time + stairs[i].len;
			stairs[i].usrNum++;
		}
	}
}

void moveComplete(int time) {
	for (int i = 0; i < people.size(); i++) {
		if (people[i].endTime == time) {
			int stair_idx = path[i];

			people[i].finish = 1;
			stairs[stair_idx].usrNum--;
		}
	}
}

bool check_finish() {
	for (int i = 0; i < people.size(); i++) {
		if (people[i].finish == 0) return false;
	}
	return true;
}

void simulation() {
	init_sim();
	cal_dist();

	int time = 0;
	while (1) {
		moveComplete(time);
		if (check_finish()) break;
		goToStair(time);
		goingDown(time);
		time++;
	}

	min_time = min(min_time, time + 1);
}

void DFS(int lv) {
	if (lv == people.size()) {
		simulation();
		return;
	}

	for (int i = 0; i < 2; i++) {
		path.push_back(i);
		DFS(lv + 1);
		path.pop_back();
	}
}

void solve() {
	DFS(0);
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
		cout << "#" << tc << " " << min_time << "\n";
	}

	return 0;
}