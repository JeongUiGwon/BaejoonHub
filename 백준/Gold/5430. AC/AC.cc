#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		string func, arr;
		int n;
		int flag_error = 0;
		int dir = 0;
		deque<int> nums;
		deque<int> dq_tmp;
		cin >> func;
		cin >> n;
		cin >> arr;

		int start = 1;
		int end = 1;
		for (int i = 1; i < arr.length(); i++)
		{
			if (arr[i] == ',' || arr[i] == ']')
			{
				end = i;
				if (start == end) break;

				string temp = arr.substr(start, end - start);
				int num = stoi(temp);
				nums.push_back(num);
				start = i + 1;
			}
		}

		for (int i = 0; i < func.length(); i++)
		{
			if (func[i] == 'R')
			{
				dir ^= 1;
			}
			else if (func[i] == 'D')
			{
				if (nums.empty())
				{
					flag_error = 1;
					break;
				}
				else
				{
					if (dir == 0) nums.pop_front();
					if (dir == 1) nums.pop_back();
				}
			}
		}

		if (flag_error) cout << "error\n";
		else
		{
			cout << "[";
			if (dir == 0)
			{
				while (!nums.empty())
				{
					int temp = nums.front();
					nums.pop_front();
					cout << temp;

					if (!nums.empty()) cout << ",";
				}
			}
			if (dir == 1)
			{
				while (!nums.empty())
				{
					int temp = nums.back();
					nums.pop_back();
					cout << temp;

					if (!nums.empty()) cout << ",";
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}