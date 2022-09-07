#include <iostream>
using namespace std;
int factorial(int n) {
    if(n<=1)
        return 1;
    else  
        return n*factorial(n-1);
}
int main() {
    int n,k,result;
    cin >> n >> k;
    if(k<0) 
        result = 0;
    if(k>n) 
        result = 0;
    else 
        result = factorial(n)/(factorial(k)*factorial(n-k));
    cout << result;
    return 0;
}