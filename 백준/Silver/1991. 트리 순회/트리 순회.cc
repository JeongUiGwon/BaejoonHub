#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[30];
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;

void dfs(int node) {	
	if (node == -1) return;

	preorder.push_back(node);

	dfs(graph[node][0]);

	inorder.push_back(node);

	dfs(graph[node][1]);

	postorder.push_back(node);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char parent, child1, child2;
		cin >> parent >> child1 >> child2;

		int p = parent - 'A';
		int c1 = child1 - 'A';
		if (child1 == '.') c1 = -1;
		int c2 = child2 - 'A';
		if (child2 == '.') c2 = -1;
		
		graph[p].push_back(c1);
		graph[p].push_back(c2);
	}

	dfs(0);

	for (int i = 0; i < preorder.size(); i++)
		cout << (char)(preorder[i] + 'A');

	cout << "\n";

	for (int i = 0; i < inorder.size(); i++)
		cout << (char)(inorder[i] + 'A');

	cout << "\n";

	for (int i = 0; i < postorder.size(); i++)
		cout << (char)(postorder[i] + 'A');

	cout << "\n";

	return 0;
}