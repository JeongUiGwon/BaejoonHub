#include <cstdio>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int main()
{
	int N, M;
	vector<int> sequence;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);
		sequence.push_back(num);
	}

	int start = 0;
	int end = 0;
	int sum = sequence[0];
	int min_size = INF;

	while (end < N)
	{
		if (sum < M) 
		{
			end++;
			if (end > N - 1) break;
			sum += sequence[end];
		}
		else
		{
			min_size = min(min_size, end - start + 1);
			sum -= sequence[start++];
		}
	}

	int ret = 0;
	if (min_size != INF) ret = min_size;

	printf("%d", ret);

	return 0;
}