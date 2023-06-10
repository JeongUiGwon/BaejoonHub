#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// 전체 용액의 수 입력
	int N;
	cin >> N;

	vector<long long> numbers(N);

	// 용액의 특성값 입력
	for (int i = 0; i < N; i++)
		cin >> numbers[i];

	int left = 0;	// 제일 첫 번째 인덱스
	int right = N - 1; // 제일 마지막 인덱스
	long long minVal = 3000000000;
	long long val1 = numbers[left]; // 정답이 될 용액의 특성값 1
	long long val2 = numbers[right]; // 정답이 될 용액의 특성값 2

	// 양 끝의 인덱스를 가운데로 이동하면서 서로 교차되거나 만날 때까지 동작
	while (left < right)
	{
		long long temp = numbers[left] + numbers[right]; // 2개의 용액의 특성값 합

		// 만약에 2개의 용액의 특성값이 최소값이라면 갱신
		if (minVal > abs(temp))
		{
			minVal = abs(temp);
			val1 = numbers[left];
			val2 = numbers[right];
		}

		if (temp < 0) left++;  // 2개 용액의 특성값 합이 음수라면, 왼쪽 인덱스를 오른쪽으로 이동(합산 값이 0에 가깝게 조정)
		else if (temp > 0) right--;  // 2개 용액의 특성값 합이 양수라면, 오른쪽 인덱스를 왼쪽으로 이동(합산 값이 0에 가깝게 조정)
		else break; // 2개 용액의 특성값 합이 0이라면, 더 이상 작아질 수 없으므로 값 반환
	}

	// 2개 용액의 특성값의 합산이 최저일 때 값 출력
	cout << val1 << " " << val2;

	return 0;
}