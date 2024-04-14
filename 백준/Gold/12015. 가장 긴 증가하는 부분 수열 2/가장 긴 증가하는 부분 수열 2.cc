#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000001

using namespace std;

int nums[MAX_N];
vector<int> ans;

int binary_search(int n)
{
	int low = 0;
	int high = ans.size() - 1;
	int ret = MAX_N;

	while (low <= high) {
		int mid = (low + high) / 2;
		int num = ans[mid];

		if (num >= n) {
			ret = min(ret, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	ans.push_back(nums[0]);

	for (int i = 1; i < N; i++) {
		if (ans.back() < nums[i])
			ans.push_back(nums[i]);
		else {
			int idx = binary_search(nums[i]);
			ans[idx] = nums[i];
		}
	}

	cout << ans.size();

	return 0;
}