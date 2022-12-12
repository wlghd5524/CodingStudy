#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0;i<t;i++) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int j = 0;j<n;j++) {
            cin >> arr[j];
        }
        sort(arr.begin(),arr.end());
        int a = 0;
        int b = n-1;
        map<int,int> cnt;
        int equal_cnt = 0;
        while(a<b) {
            if(arr[a]+arr[b] < k) {
                cnt[k-(arr[a]+arr[b])]++;
                a++;
            }
            else if(arr[a]+arr[b] > k) {
                cnt[(arr[a]+arr[b])-k]++;
                b--;
                
            }
            else if(arr[a]+arr[b] == k) {
                equal_cnt++;
                b--;
            }
        }
        vector<pair<int,int>> vec(cnt.begin(),cnt.end());
        sort(vec.begin(),vec.end());
        if(equal_cnt==0) {
            cout << cnt.begin()->second << "\n";
        }
        else {
            cout << equal_cnt << "\n";
        }
    }
}