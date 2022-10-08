#include <iostream>
#define INF 987654321
using namespace std;

int min_cost = INF;
int rate_plan[4];
int month_plan[13];
int cost_table[13];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// T : test case
	int T;
	cin >> T;

	// tc : test case num
	for (int tc = 1; tc <= T; tc++) {

		// init
		min_cost = INF;

		// rate_plan : 0 = 1 day, 1 = 1 month, 2 = 3 month, 3 = 1 year
		for (int i = 0; i < 4; i++)
			cin >> rate_plan[i];

		for (int i = 1; i <= 12; i++)
			cin >> month_plan[i];

		// 1 year rate
		min_cost = rate_plan[3];

		// calculate minimum cost through DP
		for (int i = 1; i <= 12; i++) {
			int cost_day = INF;
			int cost_month = INF;
			int cost_3month = INF;
			int min_cost_date = INF;

			cost_day = month_plan[i] * rate_plan[0] + cost_table[i - 1];
			cost_month = rate_plan[1] + cost_table[i - 1];
			if (i >= 3) cost_3month = rate_plan[2] + cost_table[i - 3];

			min_cost_date = min(cost_day, cost_month);
			min_cost_date = min(min_cost_date, cost_3month);

			cost_table[i] = min_cost_date;
		}

		// compare the 1 year rate with calculated rate
		min_cost = min(min_cost, cost_table[12]);

		cout << "#" << tc << " " << min_cost << '\n';
	}

	return 0;
}