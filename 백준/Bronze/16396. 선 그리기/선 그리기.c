#include <stdio.h>
int main()
{
    int line[10001] = {0,}; // 줄이 그어져 있는 부분. line[1] = 1이면 좌표 1~2구간에 줄이 그어져 있다는 것
    int result = 0;
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = 0;
        scanf("%d %d", &x, &y);
        for (int j = x; j < y; j++)
        {
            line[j] = 1;
        }
    }
    int startPoint = -1;
    int endPoint = -1;
    for (int i = 1; i <= 10000; i++)
    {
        if (line[i] == 1)
        {
            result++;
        }
    }
    printf("%d", result);
    return 0;
}