#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    char *seats = (char *)malloc(sizeof(char) * n);
    scanf("%s", seats);
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (seats[i] == 'S')
        {
            count++;
        }
        else if (seats[i] == 'L')
        {
            count++;
            i++;
        }
    }
    if (n < count)
    {
        count = n;
    }
    printf("%d", count);
    free(seats);
    return 0;
}