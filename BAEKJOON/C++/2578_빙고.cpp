#include <iostream>
using namespace std;
int main() {
    string b[5];
    int board[5][5];
    int tmp,count = 0;
    for(int i=0;i<5;i++) {
        /*
        for(int j=0;j<5;j++) {
            cin >> board[i][j];
        }
        */
       getline(cin,b[i]);
    }
    for(int i=0;i<25;i++) {
        cin >> tmp;
        for(int j=0;j<5;j++) {
            if(b[i].find(tmp)!=string::npos) {
                
            }
        }
        if()
        count++;
    }
}