#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <queue>
#include <algorithm>
#include <unordered_map>
#define INF 987654321
using namespace std;

vector<long long> nums;
vector<long long> sort_nums;
unordered_map<long long, long long> unorder;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long n;
		cin >> n;
		nums.push_back(n);
		sort_nums.push_back(n);
	}

	sort(sort_nums.begin(), sort_nums.end());

	sort_nums.erase(unique(sort_nums.begin(), sort_nums.end()), sort_nums.end());

	for (int i = 0; i < sort_nums.size(); i++)
	{
		unorder[sort_nums[i]] = i;
	}

	for (int i = 0; i < N; i++)
	{
		cout << unorder[nums[i]] << " ";
	}

	return 0;
}