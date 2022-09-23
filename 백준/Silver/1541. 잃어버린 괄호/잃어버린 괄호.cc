#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

vector<int> nums;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	cin >> str;

	int start = 0;
	int end = 0;
	int sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '+')
		{
			end = i;
			int num = stoi(str.substr(start, end - start));
			sum += num;
			start = i + 1;
		}
		else if (str[i] == '-')
		{
			end = i;
			int num = stoi(str.substr(start, end - start));
			sum += num;
			nums.push_back(sum);
			sum = 0;
			start = i + 1;
		}
		else if (i == str.length() - 1)
		{
			end = i + 1;
			int num = stoi(str.substr(start, end - start));
			sum += num;
			nums.push_back(sum);
		}
	}

	int ans = nums[0];
	for (int i = 1; i < nums.size(); i++)
		ans -= nums[i];

	cout << ans;

	return 0;
}