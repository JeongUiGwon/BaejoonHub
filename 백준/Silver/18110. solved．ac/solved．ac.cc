#include<stdio.h>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int main()
{
    vector <int> vec;
    int N;
    int number;
    scanf("%d", &N);
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &number);
        vec.push_back(number);
    }    
    sort(vec.begin(), vec.end()); // 정렬 
    double num;
    num = (double)N * 15 / 100;
    int value = num;
    if (num - value >= 0.5)
        value++;
    int cnt = 0;
    int sum = 0;
    for (int i = value; i < N - value; i++)
    {
        sum = vec[i] + sum;
        cnt++;
    }
    double avg = (double)sum/(double)cnt;
    int avg_2=avg;
    if (avg - avg_2 >= 0.5)
        avg_2++;
    printf("%d", avg_2);
}
