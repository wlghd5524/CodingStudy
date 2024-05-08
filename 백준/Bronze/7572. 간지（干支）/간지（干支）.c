#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int ten = 7;
    int twelve = 9;
    for (int i = 1; i < n; i++)
    {
        ten++;
        twelve++;
        if (ten == 10)
        {
            ten = 0;
        }
        if (twelve == 12)
        {
            twelve = 0;
        }
    }
    printf("%c%d", twelve + 'A', ten);
    return 0;
}