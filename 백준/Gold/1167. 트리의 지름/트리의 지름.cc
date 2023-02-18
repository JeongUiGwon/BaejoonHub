#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

vector<pair<int, int>> tree[MAX];
bool visited[MAX] = {false, };
int result = 0;
int farthestNode = 0;

void dfs(int node, int sum) {
    if (visited[node]) return;
    visited[node] = true;

    if (result < sum) {
        result = sum;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        int weight = tree[node][i].second;
        dfs(nextNode, sum + weight);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin >> V;

    for (int i = 1; i <= V; i++) {
        int node;
        cin >> node;

        while (true) {
            int neighbor, weight;
            cin >> neighbor;

            if (neighbor == -1) break;

            cin >> weight;
            tree[node].push_back(make_pair(neighbor, weight));
            tree[neighbor].push_back(make_pair(node, weight));
        }
    }

    dfs(1, 0);
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }

    dfs(farthestNode, 0);
    cout << result << "\n";

    return 0;
}