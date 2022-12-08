#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> solutions(n);
    for(int i = 0;i<n;i++) {
        cin >> solutions[i];
    }
    sort(solutions.begin(),solutions.end());
    int a = 0;
    int b = n-1;
    int min = 2000000000;
    pair<int,int> result;
    while(a < b) {
        int sum = solutions[a]+solutions[b];
        if(abs(sum) == 0) {
            result = {solutions[a],solutions[b]};
            break;
        }
        if(abs(sum) < min) {
            min = abs(sum);
            result = {solutions[a],solutions[b]};
        }
        if(sum < 0) {
            a++;
        }
        else {
            b--;
        }
    }
    cout << result.first << " " << result.second;
    return 0;
}