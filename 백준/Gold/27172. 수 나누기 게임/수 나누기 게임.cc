#include <iostream>
using namespace std;
int n;
int arr[100000];
int score[1000001];
bool cards[1000001];
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i] * 2; j <= 1000000; j += arr[i])
        {
            if (cards[j])
            {
                score[j]--;
                score[arr[i]]++;
            }
        }
    }
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        cards[arr[i]] = true;
    }
    solve();
    for (int i = 0; i < n; i++)
    {
        cout << score[arr[i]] << " ";
    }
    return 0;
}