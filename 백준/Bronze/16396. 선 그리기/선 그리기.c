#include <stdio.h>
int main()
{
    int line[10001] = {
        0,
    };
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
        if(line[i] == 1) {
            result++;
        }




        // if (line[i] == 1 && line[i - 1] != 1)
        // {
        //     startPoint = i;
        // }
        // if ((line[i] == 0 && line[i - 1] == 1))
        // {
        //     endPoint = i - 1;
        //     result += (endPoint - startPoint);
        // }
        // if (i == 10000 && line[i] == 1)
        // {
        //     endPoint = i;
        //     result += (endPoint - startPoint);
        // }
    }
    printf("%d", result);
    return 0;
}