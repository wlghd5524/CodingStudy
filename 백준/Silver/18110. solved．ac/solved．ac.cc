#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n == 0) {
        cout << 0;
        return 0;
    }
    int arr[n];
    double except = round(n * 15.0 / 100.0); //절사평균을 위해 제외할 인덱스
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    double sum = 0;
    for (int i = except; i < n - except; i++)  //앞에서부터 15% 뒤에서부터 15%를 제외하여 합 구하기
    {
        sum += arr[i];
    }
    cout << round(sum / (n - (except * 2)));  //평균 구하기
    return 0;
}