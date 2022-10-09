#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct CustomerInfo {
	int num, arriveTime, recept_num, receptTime, repair_num, repairTime;
};

int N, M, K, A, B;
int receptions[10];
int repair_station[10];
queue<CustomerInfo> customers;
queue<CustomerInfo> wait_receipt;
queue<CustomerInfo> wait_repair;
queue<CustomerInfo> finish_customers;
CustomerInfo customer_receipt[10];
CustomerInfo customer_repair[10];
CustomerInfo customer_empty = { 0, 0, 0, 0, 0, 0 };

void init() {
	while (!finish_customers.empty()) finish_customers.pop();
}

void input() {
	cin >> N >> M >> K >> A >> B;

	for (int i = 1; i <= N; i++) {
		cin >> receptions[i];
	}

	for (int i = 1; i <= M; i++)
		cin >> repair_station[i];

	for (int i = 0; i < K; i++) {
		int time;
		cin >> time;
		customers.push({ i + 1, time, 0, -1, 0, -1 });
	}
}

void register_receipt(int time) {
	int cnt = customers.size();

	for (int i = 0; i < cnt; i++) {
		CustomerInfo customer = customers.front();
		customers.pop();

		if (customer.arriveTime == time) {
			wait_receipt.push(customer);
		}
		else {
			customers.push(customer);
		}

	}
}

void recept(int time) {
	int cnt = wait_receipt.size();

	for (int i = 0; i < cnt; i++) {
		CustomerInfo customer = wait_receipt.front();

		int flag_full = 1;
		for (int j = 1; j <= N; j++) {
			if (customer_receipt[j].num == 0) {
				customer_receipt[j] = customer;
				customer_receipt[j].recept_num = j;
				customer_receipt[j].receptTime = time;
				flag_full = 0;
				break;
			}
		}

		if (flag_full) break;

		wait_receipt.pop();
	}
}

void register_repair(int time) {
	for (int i = 1; i <= N; i++) {
		CustomerInfo customer = customer_receipt[i];

		if (customer.num == 0) continue;

		int finish_time = customer.receptTime + receptions[i];
		
		if (finish_time == time) {
			wait_repair.push(customer);
			customer_receipt[i] = customer_empty;
		}
	}
}

void repair(int time) {
	int cnt = wait_repair.size();

	for (int i = 0; i < cnt; i++) {
		CustomerInfo customer = wait_repair.front();

		int flag_full = 1;
		for (int j = 1; j <= M; j++) {
			if (customer_repair[j].num == 0) {
				customer_repair[j] = customer;
				customer_repair[j].repair_num = j;
				customer_repair[j].repairTime = time;
				flag_full = 0;
				break;
			}
		}

		if (flag_full) break;

		wait_repair.pop();
	}
}

void finish(int time) {
	for (int i = 1; i <= M; i++) {
		CustomerInfo customer = customer_repair[i];

		if (customer.num == 0) continue;

		int finish_time = customer.repairTime + repair_station[i];

		if (finish_time == time) {
			finish_customers.push(customer);
			customer_repair[i] = customer_empty;
		}
	}
}

void simulation() {
	int time = -1;
	while (finish_customers.size() < K) {
		time++;
		finish(time);
		register_repair(time);
		repair(time);
		register_receipt(time);
		recept(time);
	}
}

void output(int tc) {
	int ans = 0;
	while (!finish_customers.empty()) {
		CustomerInfo customer = finish_customers.front();
		finish_customers.pop();

		if (customer.recept_num == A && customer.repair_num == B) {
			ans += customer.num;
		}
	}

	if (ans == 0) ans = -1;
	cout << "#" << tc << " " << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		init();
		input();
		simulation();
		output(tc);
	}

	return 0;
}