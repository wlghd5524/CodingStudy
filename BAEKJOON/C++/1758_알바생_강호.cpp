#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    long long int sum = 0;
    cin >> n;
    multiset<int,greater<int>> s;
    for(int i=0;i<n;i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }
    int i = 0;
    for(auto iter = s.begin();iter!=s.end();iter++) {
        if(*iter-i>0) {
            sum += (*iter-i);
        }
        i++;
    }
    cout << sum;
}