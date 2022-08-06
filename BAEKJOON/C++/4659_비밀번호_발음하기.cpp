#include <iostream>
#include <string>
using namespace std;
int main() {
    string str;
    while(1) {
        bool check[3] = {false,true,true};
        cin >> str;
        if(str=="end") {
            break;
        }
        for(int i=0;i<str.size();i++) {
            if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u') {
                if(str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u') {
                    if(str[i+2]=='a'||str[i+2]=='e'||str[i+2]=='i'||str[i+2]=='o'||str[i+2]=='u') {
                        check[1] = false;
                    }
                }
                check[0] = true;

            }
            else {
                if(str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u') {}
                else {
                    if(str[i+2]=='a'||str[i+2]=='e'||str[i+2]=='i'||str[i+2]=='o'||str[i+2]=='u') {}
                    else {
                        check[1] = false;
                    }
                }
            }
            if(str[i]==str[i+1]) {
                if((str[i]=='e'&&str[i+1]=='e')||(str[i]=='o'&&str[i+1]=='o')) {}
                else {
                    check[2] = false;
                }
            }
        }

        if(check[0]==true&&check[1]==true&&check[2]==true) {
            cout << "<" << str << ">" << " is acceptable.\n";
        }
        else {
            cout << "<" << str << ">" << " is not acceptable.\n";
        }
        
    }
}