#include <iostream>
#include <queue>
using namespace std;

struct CONSULT {
    long long start_time, end_time;
};

bool operator<(CONSULT a, CONSULT b) {
    if (a.start_time < b.start_time) return true;
    if (a.start_time > b.start_time) return false;

    if (a.end_time < b.end_time) return true;
    if (a.end_time > b.end_time) return false;
    return false;
}

priority_queue<CONSULT> consults;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        long long start, end;
        cin >> start >> end;

        consults.push({ start, end });
    }

    long long time = consults.top().end_time + 1;
    int consult_cnt = 0;
    while (!consults.empty())
    {
        CONSULT now = consults.top();
        consults.pop();

        if (now.end_time <= time)
        {
            consult_cnt++;
            time = now.start_time;
        }
    }

    cout << consult_cnt;

    return 0;
}