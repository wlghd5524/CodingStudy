#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    int *arr = (int *)malloc(sizeof(int) * (b + 1));
    arr[0] = 0;
    int index = 1;
    for (int i = 1; index <= b; i++)
    {
        for (int j = 0; j < i; j++)
        {
            arr[index] = arr[index - 1] + i;
            index++;
            if (index > b)
            {
                break;
            }
        }
    }
    int sum = 0;
    printf("%d", arr[b] - arr[a - 1]);
    free(arr);
    return 0;
}