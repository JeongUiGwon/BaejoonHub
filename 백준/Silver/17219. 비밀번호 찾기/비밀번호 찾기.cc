#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, string> pwds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string site, pw;
		cin >> site >> pw;

		pwds[site] = pw;
	}

	for (int i = 0; i < M; i++)
	{
		string site, pw;
		cin >> site;
		cout << pwds[site] << '\n';
	}

	return 0;
}