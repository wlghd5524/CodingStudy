#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for (int i = 0; i < k; i++)
    {
        max += arr[i];
    }
    int start = 1; // 연속되는 수열 중 첫 인덱스
    int end = k;   // 연속되는 수열 중 마지막 인덱스
    int sum = max;
    while (end != n)
    {
        sum += (arr[end] - arr[start - 1]);
        if (max < sum)
        {
            max = sum;
        }
        start++;
        end++;
    }
    printf("%d", max);
    free(arr);
    return 0;
}