#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = arr[left] + arr[right];
            if (sum == num)
            {
                if (left != i && right != i)
                {
                    result++;
                    break;
                }
                else if (left == i)
                {
                    left++;
                }
                else if (right == i)
                {
                    right--;
                }
            }
            else if (sum < num)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
    cout << result;
    return 0;
}