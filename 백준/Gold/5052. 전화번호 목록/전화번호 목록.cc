#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t;
    
    for(int i=0;i<t;i++) {
        bool answer = true;
        cin >> n;
        cin.ignore();
        set<string> s;
        string tmp;
        for(int j=0;j<n;j++) {
            //cin >> tmp;
            getline(cin,tmp);
            tmp.erase(remove(tmp.begin(),tmp.end(),' '),tmp.end());
            s.insert(tmp);
        }

        int cnt = 0;
        for(auto iter = s.begin();iter!=s.end();iter++) {
            if(cnt<s.size()-1) {
                auto iter_tmp = ++iter;
                iter--;
                if(iter_tmp->find(*iter) == 0) {
                    answer = false;
                    break;
                }
            }
            cnt++;
        }
        if(answer == true) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}