#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int n;
        cin >> n;
        vector<int> score(n);
        for (int j = 0; j < n; j++)
        {
            cin >> score[j];
        }
        sort(score.begin(), score.end());
        int gap_max = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (score[j + 1] - score[j] > gap_max)
            {
                gap_max = score[j + 1] - score[j];
            }
        }
        cout << "Class " << i << "\nMax " << score[n - 1] << ", Min " << score[0] << ", Largest gap " << gap_max << "\n";
    }
    return 0;
}