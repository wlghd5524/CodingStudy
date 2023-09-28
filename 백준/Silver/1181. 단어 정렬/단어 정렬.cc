#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(string a, string b) // sort 정렬 조건 함수
{
    if (a.size() == b.size()) // a와 b의 길이가 같을 때
    {
        return a < b; // 사전순
    }
    return a.size() < b.size(); // 길이가 작은 순
}
int main()
{
    int n;
    cin >> n;
    vector<string> list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    sort(list.begin(), list.end(), compare);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cout << list[i] << "\n";
            continue;
        }
        if (list[i] != list[i - 1]) // 중복되는 문자열 출력 X
        {
            cout << list[i] << "\n";
        }
    }
    return 0;
}
