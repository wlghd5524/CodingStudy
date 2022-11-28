#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    int sum_Y = 0;
    int sum_M = 0;
    for(int i = 0;i<n;i++) {
        int call_time = 0;
        int call_Y_cost = 0;
        int call_M_cost = 0;
        cin >> call_time;
        call_Y_cost = ((call_time / 30) + 1) * 10;
        call_M_cost = ((call_time / 60) + 1) * 15;
        sum_Y += call_Y_cost;
        sum_M += call_M_cost;
    }
    if(sum_M < sum_Y) {
        cout << "M " << sum_M; 
    }
    else if(sum_M > sum_Y) {
        cout << "Y " << sum_Y;
    }
    else {
        cout << "Y M " << sum_M;
    }
    return 0;
}