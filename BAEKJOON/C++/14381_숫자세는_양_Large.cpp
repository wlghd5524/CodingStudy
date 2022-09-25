#include <iostream>
using namespace std;
string bigNumAdd(string x, string y) {
    if(x.size() < y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    for(int i = y.size(); i < x.size(); i++) {
        y = "0" + y;
    }
    for(int i = x.size()-1; i >= 0; i--) {
        int tmp = (x[i]-'0') + (y[i]-'0');
        if(tmp >= 10) {
            tmp -= 10;
            if(i == 0) {
                x = "1" + x;
                x[i+1] = tmp + '0';
                break;
            }
            else {
                x[i-1]++;
            }
        }
        x[i] = tmp + '0';
    }
    return x;
}
int main() {
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
        string record = "0000000000";
        string n;
        cin >> n;
        string j = n;
        string result;
        while(n!="0") {
            for(int p = 0; p<j.size();p++) {
                record[j[p] - '0'] = '1';
            }
            if(record=="1111111111") {
                result = j;
                break;
            }
            j = bigNumAdd(j,n);
        }
        if(n == "0") {
            cout << "Case #" << i+1 << ": INSOMNIA\n";
            continue;
        }
        cout << "Case #" << i+1 << ": " << result << "\n";
    }
    return 0;
}