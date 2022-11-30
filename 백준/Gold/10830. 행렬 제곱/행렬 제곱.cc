#include <iostream>
using namespace std;

long long N, B;
long long matrix[5][5];
long long ans[5][5];

void input() {
	cin >> N >> B;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> matrix[y][x];
		}
		ans[y][y] = 1;
	}
}

void multi_matrix(long long matrix1[5][5], long long matrix2[5][5]) {
	long long tmp[5][5];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			long long sum = 0;

			for (int i = 0; i < N; i++) {
				sum += matrix1[y][i] * matrix2[i][x];
			}

			tmp[y][x] = sum % 1000;
		}
	}

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			matrix1[y][x] = tmp[y][x];
}

void solve() {
	while (B > 0) {
		if (B % 2 == 1)
			multi_matrix(ans, matrix);

		multi_matrix(matrix, matrix);
		B /= 2;
	}
}

void print_matrix(long long matrix1[5][5]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << matrix1[y][x] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	input();
	solve();
	print_matrix(ans);

	return 0;
}