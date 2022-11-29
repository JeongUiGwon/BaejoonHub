#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2, ans = "";
	cin >> s1 >> s2;

	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 0; i < s1.length(); i++) {
		ans += s1[i];

		if (ans.length() >= len2) {
			bool flag = true;

			for (int j = 0; j < len2; j++) {
				if (ans[ans.length() - len2 + j] != s2[j]) {
					flag = false;
					break;
				}
			}

			if (flag)
				ans.erase(ans.end() - len2, ans.end());
		}
	}

	if (ans.empty())
		cout << "FRULA" << '\n';
	else
		cout << ans << '\n';

	return 0;
}