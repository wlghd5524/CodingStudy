#include <stdio.h>
int main()
{
    int N = 0;
    int number[10001] = {   //각 인덱스 값에 해당하는 숫자의 개수 저장
        0,
    };
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        number[num]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 0; j < number[i]; j++)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}