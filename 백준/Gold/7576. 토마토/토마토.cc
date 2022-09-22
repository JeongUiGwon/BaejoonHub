#include <iostream>
#include <queue>
using namespace std;

struct TOMATO
{
    int y, x, time;
};

int M, N, take_time;
int map[1003][1003];
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
queue<TOMATO> q;

void bfs() 
{
    while (!q.empty())
    {
        int nowY = q.front().y;
        int nowX = q.front().x;
        take_time = q.front().time;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextY = nowY + dy[i];
            int nextX = nowX + dx[i];

            if (nextY < 0 || nextY >= N || nextX < 0 || nextX >= M) continue;
            if (map[nextY][nextX] == 1) continue;
            if (map[nextY][nextX] == -1) continue;

            map[nextY][nextX] = 1;
            q.push({ nextY, nextX, take_time + 1 });
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> map[y][x];
            if (map[y][x] == 1)
            {
                q.push({ y, x, 0 });
            }
        }
    }

    bfs();

    int flag_fail = 0;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            if (map[y][x] == 0)
            {
                flag_fail = 1;
                break;
            }
        }
        if (flag_fail) break;
    }

    if (flag_fail) take_time = -1;

    cout << take_time;

    return 0;
}