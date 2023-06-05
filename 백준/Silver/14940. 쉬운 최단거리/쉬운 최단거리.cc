#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[1003][1003]; // map 정보
int dist[1003][1003]; // 방문 여부 체크
pair<int, int> goal_pos; // 도연이 위치

// 방향 배열(상하좌우)
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, -1, 0, 1 };

// BFS (너비 우선 탐색) 알고리즘
void bfs()
{
	// 시작점을 queue에 저장 (시작점 : 도연이의 위치)
	queue<pair<int, int>> q;
	q.push(goal_pos);
	dist[goal_pos.first][goal_pos.second] = 0; // 방문 여부 체크

	// 더 이상 갈 공간이 없을 떄 까지 무한 반복
	while (!q.empty())
	{
		// 현재 위치
		pair<int, int> cur = q.front();
		q.pop();

		// 방향 배열(dy[], dx[])을 통해 상하좌우 체크
		for (int i = 0; i < 4; i++)
		{
			// 이동할 위치
			pair<int, int> next = { cur.first + dy[i], cur.second + dx[i] };

			if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) continue;
			if (dist[next.first][next.second] != -1) continue; // 벽일 경우, 스킵

			// 다음 위치 저장 및 방문 여부 체크
			q.push(next);
			dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
		}
	}
}

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill(&dist[0][0], &dist[1002][1002], -1);

	// 캠퍼스 크기 입력
	cin >> N >> M;

	// 캠퍼스 정보 입력
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> map[y][x];

			// 도연이의 위치 저장
			if (map[y][x] == 2)
			{
				goal_pos.first = y;
				goal_pos.second = x;
			}

			if (map[y][x] == 0) dist[y][x] = 0;
		}
	}

	// BFS 알고리즘을 통해 도연이가 만날 수 있는 사람의 수 계산
	bfs();

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cout << dist[y][x] << " ";
		}
		cout << "\n";
	}

	return 0;
}