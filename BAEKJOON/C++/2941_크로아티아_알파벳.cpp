#include <iostream>

using namespace std;

int main() {
    string str;
    int count = 0;
    cin >> str;
    for(int i=0;i<str.length();i++) {
        if(str[i]=='z' && str[i-1]=='d' && str[i+1]=='=')
            continue;
        if((str[i]=='j'&&str[i-1]=='l')||(str[i]=='j'&&str[i-1]=='n'))
            continue;
        if(str[i]=='-'||str[i]=='=')
            continue;
        count++;
    }
    cout << count;
    return 0;
}