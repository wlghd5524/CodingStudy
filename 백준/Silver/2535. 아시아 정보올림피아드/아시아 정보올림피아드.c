#include <stdio.h>
typedef struct students
{
    int country;
    int num;
    int score;
} students;
int main()
{
    students st[100];
    int country[101] = {
        0,
    };
    int N = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &st[i].country, &st[i].num, &st[i].score);
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (st[i].score > st[j].score)
            {
                students temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        if (country[st[i].country] < 2)
        {
            printf("%d %d\n", st[i].country, st[i].num);
            country[st[i].country]++;
            count++;
        }
        if (count == 3)
        {
            break;
        }
    }
    return 0;
}