#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

long long M = 1234567891;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	cin >> L;

	string str;
	cin >> str;

	long long ret = 0;
	long long r = 1;
	for (int i = 0; i < L; i++)
	{
		int num = str[i] - 'a' + 1;
		ret += (num * r) % M;
		r = (r * 31) % M;
	}

	cout << ret % M;

	return 0;
}