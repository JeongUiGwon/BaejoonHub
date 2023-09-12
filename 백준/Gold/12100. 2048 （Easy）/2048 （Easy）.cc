#include <cstdio>
#include <vector>
#define INF 987654321
using namespace std;

int N;
int map[20][20];
int map_origin[20][20];
int ans = -INF;
vector<int> path;	// 이동 방향

void init_map()
{
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			map[y][x] = map_origin[y][x];
}

int get_max()
{
	int max_num = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			max_num = max(max_num, map[y][x]);

	return max_num;
}

// 0 : 윗쪽, 1 : 오른쪽, 2: 아랫쪽, 3: 왼쪽
void move_map(int dir)
{
	switch (dir)
	{
	case 0:
		for (int x = 0; x < N; x++)
		{
			vector<int> nums;
			int flag_combined = 0;
			for (int y = 0; y < N; y++)
			{
				if (map[y][x] == 0) continue;

				if (nums.size() > 0 && nums.back() == map[y][x] && !flag_combined)	// 합쳐지는 경우
				{
					nums.back() += map[y][x];
					flag_combined = 1;
				}
				else    // 합쳐지지 않는 경우
				{
					nums.push_back(map[y][x]);
					flag_combined = 0;
				}
			}

			// 계산된 nums를 천천히 map에 저장
			int idx = 0;
			for (int y = 0; y < N; y++)
			{
				if (idx < nums.size()) map[y][x] = nums[idx++];
				else map[y][x] = 0;
			}
		}
		break;

	case 1:

		for (int y = 0; y < N; y++)
		{
			vector<int> nums;
			int flag_combined = 0;
			for (int x = N - 1; x >= 0; x--)
			{
				if (map[y][x] == 0) continue;

				if (nums.size() > 0 && nums.back() == map[y][x] && !flag_combined)
				{
					nums.back() += map[y][x];
					flag_combined = 1;
				}
				else
				{
					nums.push_back(map[y][x]);
					flag_combined = 0;
				}
			}

			int idx = 0;
			for (int x = N - 1; x >= 0; x--)
			{
				if (idx < nums.size()) map[y][x] = nums[idx++];
				else map[y][x] = 0;
			}
		}
		break;

	case 2:
		for (int x = 0; x < N; x++)
		{
			vector<int> nums;
			int flag_combined = 0;
			for (int y = N - 1; y >= 0; y--)
			{
				if (map[y][x] == 0) continue;

				if (nums.size() > 0 && nums.back() == map[y][x] && !flag_combined)
				{
					nums.back() += map[y][x];
					flag_combined = 1;
				}
				else
				{
					nums.push_back(map[y][x]);
					flag_combined = 0;
				}
			}

			int idx = 0;
			for (int y = N - 1; y >= 0; y--)
			{
				if (idx < nums.size()) map[y][x] = nums[idx++];
				else map[y][x] = 0;
			}
		}
		break;

	case 3:

		for (int y = 0; y < N; y++)
		{
			vector<int> nums;
			int flag_combined = 0;
			for (int x = 0; x < N; x++)
			{
				if (map[y][x] == 0) continue;

				if (nums.size() > 0 && nums.back() == map[y][x] && !flag_combined)
				{
					nums.back() += map[y][x];
					flag_combined = 1;
				}
				else
				{
					nums.push_back(map[y][x]);
					flag_combined = 0;
				}
			}

			int idx = 0;
			for (int x = 0; x < N; x++)
			{
				if (idx < nums.size()) map[y][x] = nums[idx++];
				else map[y][x] = 0;
			}
		}
		break;

	default:
		break;
	}
}

void dfs(int lv)
{
	// 5번 이동했을 때, 가장 큰 블록 값 찾기
	if (lv == 5)
	{
		// map 초기화
		init_map();

		// 맵 이동
		for (int i = 0; i < path.size(); i++)
			move_map(path[i]);

		int max_num = get_max();
		ans = max(ans, max_num);
		return;
	}

	// 각 방향에 대해 path 저장
	for (int i = 0; i < 4; i++)
	{
		path.push_back(i);
		dfs(lv + 1);
		path.pop_back();
	}
}

int main()
{
	// N(보드의 크기) 입력
	scanf("%d", &N);

	// Map 정보 입력
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			scanf("%d", &map_origin[y][x]);

	dfs(0);

	printf("%d", ans);

	return 0;
}