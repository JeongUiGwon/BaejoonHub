#include <iostream>
#include <string>
#include <vector>
using namespace std;

int sum_table[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int num;
		cin >> num;
		sum += num;
		sum_table[i] = sum;
	}

	for (int i = 0; i < M; i++)
	{
		int start, end;
		cin >> start >> end;

		cout << sum_table[end] - sum_table[start - 1] << '\n';
	}

	return 0;
}