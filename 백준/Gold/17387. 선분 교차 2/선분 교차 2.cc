#include <iostream>
#include <algorithm>

using namespace std;

pair<long long, long long> A;
pair<long long, long long> B;
pair<long long, long long> C;
pair<long long, long long> D;

int ccw(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> p3)
{
	long long temp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
	temp -= p1.second * p2.first + p2.second * p3.first + p3.second * p1.first;

	if (temp > 0) return 1;			// 반시계 방향
	else if (temp == 0) return 0;	// 일직선
	else return -1;					// 시계 방향
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ret = 0;

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;
	cin >> D.first >> D.second;

	if (A > B) swap(A, B);
	if (C > D) swap(C, D);

	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);

	if (ans1 == 0 && ans2 == 0) {
		if (A <= D && B >= C)
			ret = 1;
	}
	else {
		if (ans1 <= 0 && ans2 <= 0)
			ret = 1;
	}

	cout << ret;

	return 0;
}