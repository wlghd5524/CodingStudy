#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int m;
    cin >> m;
    int a = 0;
    int b = n-1;
    int result = 0;
    while (a<b)
    {
        if(arr[a]+arr[b]==m) {
            result++;
            a++;
            b--;
        }
        else if(arr[a]+arr[b]<m) {
            a++;
        }
        else if(arr[a]+arr[b]>m) {
            b--;
        }
    }
    cout << result;
    return 0;
}