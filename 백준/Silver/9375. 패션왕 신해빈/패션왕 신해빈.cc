#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		int n;
		cin >> n;

		unordered_map<string, vector<string>> clothes;
		vector<string> types;

		for (int i = 0; i < n; i++)
		{
			string cloth, type;
			cin >> cloth >> type;

			if (clothes[type].size() == 0) types.push_back(type);
			clothes[type].push_back(cloth);
		}

		int ans = 1;

		for (int i = 0; i < types.size(); i++)
		{
			ans *= (clothes[types[i]].size() + 1);
		}

		cout << ans - 1 << '\n';		
	}

	return 0;
}