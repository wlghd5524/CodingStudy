#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) // 1부터 n까지 모든 수를 브루트포스
    {
        if (i <= 99) // 99까지는 모든 양의 정수가 한수이므로 확인할 필요가 없다.
        {
            count++;
            continue;
        }
        string num = to_string(i);               // 각각의 자리 수를 추출하기 위해 숫자 i를 string으로 변환
        int diff = num[1] - num[0];              // 첫번째 자리 수와 두번째 자리 수의 차이
        bool skip = false;                       // 한수가 아닌 수를 건너뛰기 위해
        for (int j = 1; j < num.size() - 1; j++) // 두번째 자리 수부터 마지막 자리 수까지 비교
        {
            if (num[j + 1] - num[j] != diff) // j번째 자리 수와 j+1번째 자리 수의 차이가 diff와 다르다면 한수가 아니다.
            {
                skip = true;
            }
        }
        if (skip) // 한수가 아니면 +1 하지 않고 다음 수로 건너뛴다.
        {
            continue;
        }
        count++;
    }
    cout << count;
    return 0;
}
