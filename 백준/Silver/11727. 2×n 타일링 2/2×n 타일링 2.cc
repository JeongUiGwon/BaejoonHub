#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int table_case[1003];

int main() {
	int n;
	scanf("%d", &n);

	table_case[1] = 1;
	table_case[2] = 3;

	for (int i = 3; i <= n; i++)
		table_case[i] = (table_case[i - 2] * 2 + table_case[i - 1]) % 10007;

	printf("%d", table_case[n]);

	return 0;
}