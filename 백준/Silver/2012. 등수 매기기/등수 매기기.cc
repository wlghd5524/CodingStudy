#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != arr[i])
        {
            sum += abs(i + 1 - arr[i]);
        }
    }
    cout << sum;
    return 0;
}