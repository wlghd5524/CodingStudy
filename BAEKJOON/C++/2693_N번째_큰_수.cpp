#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<int> arr(10);
        for (int j = 0; j < 10; j++)
        {
            cin >> arr[j];
        }
        sort(arr.begin(), arr.end(), greater<>());
        cout << arr[2] << "\n";
    }
    return 0;
}