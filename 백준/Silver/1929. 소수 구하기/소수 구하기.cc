#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int prime_number[1000006];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    for (int i = 2; i < 1000001; i++)
    {
        prime_number[i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        if (prime_number[i] == 0) continue;
        int num = 2;
        while (i * num <= N)
        {
            prime_number[i * num] = 0;
            num++;
        }
    }

    for (int i = M; i <= N; i++)
    {
        if (prime_number[i] == 1) cout << i << '\n';
    }

    return 0;
}