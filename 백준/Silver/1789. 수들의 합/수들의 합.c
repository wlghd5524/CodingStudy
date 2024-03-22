#include <stdio.h>
int main()
{
    long long int s = 0;
    long long int sum = 0;
    scanf("%lld", &s);
    for (long long int i = 1; i <= s; i++)
    {
        if (sum + i < s)
        {
            sum += i;
        }
        else if (sum + i == s)
        {
            printf("%lld", i);
            break;
        }
        else
        {
            printf("%lld", i - 1);
            break;
        }
    }
    return 0;
}