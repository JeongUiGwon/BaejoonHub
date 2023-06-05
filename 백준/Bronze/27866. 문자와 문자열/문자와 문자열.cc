#include <iostream>
#include <string>

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word;
	int idx;

	cin >> word;
	cin >> idx;

	cout << word[idx - 1];

	return 0;
}