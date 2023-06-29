#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<float> v(100000);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<>()); //오름차순으로 정렬
    for (int i = v.size() - 1; i >= 1; i--)
    {
        v[0] += v[i] / 2;  //가장 큰 값과 가장 작은 값의 반을 더하여 가장 큰 값에 저장
    }
    cout << v[0];
    return 0;
}