#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>

using namespace std;

int arr[102];

int solve(int l, int r)
{
    int ret;
    int mid;
    
    if (l == r)
        return 1;
    
    mid = (l + r) >> 1;
    int left = (l + (mid + 1)) >> 1;
    int right = ((mid - 1) + r) >> 1;
    if (arr[mid] == 0 && (arr[left] == 1 || arr[right] == 1))
        ret = 0;
    else
        ret = min(solve(l, mid + 1), solve(mid - 1, r));
    return ret;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(int i = 0; i < numbers.size(); i++)
    {
        long long num = numbers[i];
        int len = 0;
        memset(arr, 0, sizeof(arr));
        
        while(num)
        {
            len++;
            if (num & 1)
                arr[len] = 1;
            num >>= 1;
        }
        
        //printf("len %d\n", len);
        //for(int j = len; j > 0; j--)
        //    printf("%d", arr[j]);
        //printf("\n");

        int ret = 0;
        for(int j = 1; j < 64; j = j * 2 + 1)
        {
            if (j >= len)
            {
                //printf("j %d solve %d\n", j, solve(j, 1));
                ret = max(ret, solve(j, 1));
            }
        }
        answer.push_back(ret);
    }
    
    return answer;
}