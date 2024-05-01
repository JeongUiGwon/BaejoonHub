#include <iostream>
#include <map>
#define MAX_N 40

using namespace std;

int N, S;
int arr[MAX_N];
map<int, int> sum2cnt;
long long cnt;

void rightSeq(int mid, int sum) {
	if (mid == N) {
		sum2cnt[sum]++;
		return;
	}

	rightSeq(mid + 1, sum + arr[mid]);
	rightSeq(mid + 1, sum);
}

void leftSeq(int start, int sum) {
	if (start == N / 2) {
		cnt += sum2cnt[S - sum];
		return;
	}

	leftSeq(start + 1, sum + arr[start]);
	leftSeq(start + 1, sum);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	rightSeq(N / 2, 0);
	leftSeq(0, 0);

	if (S == 0) cout << cnt - 1;
	else cout << cnt;

	return 0;
}