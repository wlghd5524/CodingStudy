#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int min = 1001;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if ((a < b || a == b) && min > b)
        {
            min = b;
        }
    }
    if (min == 1001)
    {
        printf("-1");
    }
    else
    {
        printf("%d", min);
    }
    return 0;
}