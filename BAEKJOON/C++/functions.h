#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FUNCTIONS_H

string bigNumAdd(string x, string y) {
    if(x.size() < y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    int x_leng = x.size();
    for(int i = y.size();i<x.size();i++) {
        y.insert(0,"0");
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    for(int i = 0; i < x_leng; i++) {
        int tmp = (x[i]-'0') + (y[i]-'0');
        if(tmp >= 10) {
            tmp -= 10;
            if(i+1==x.size()) {
                x.push_back('1');
            }
            else {
                x[i+1]++;
            }
        }
        x[i] = tmp + '0';
    }
    reverse(x.begin(),x.end());
    return x;
}

string bigNumSub(string x, string y) {
    if(x.size()<y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    else if(x.size() == y.size()) {
        if(x[0] < y[0]) {
            string tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
    }
    int x_leng = x.size();
    for(int i = y.size();i<x.size();i++) {
        y.insert(0,"0");
    }
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    for(int i = 0; i < x_leng; i++) {
        int tmp = (x[i]-'0') - (y[i]-'0');
        if(tmp < 0) {
            tmp += 10;
            x[i+1]--;
        }
        x[i] = tmp + '0';
    }
    reverse(x.begin(),x.end());
    while(x.find("0")!=string::npos) {
        x.erase(x.find("0"),1);
    }
    return x;
}
string bigNumMulti(string x, string y) {
    string sum;
    if(x.size()<y.size()) {
        string tmp;
        tmp = x;
        x = y;
        y = tmp;
    }
    else if(x.size() == y.size()) {
        if(x[0] < y[0]) {
            string tmp;
            tmp = x;
            x = y;
            y = tmp;
        }
    }
    int x_leng = x.size();
    int y_leng = y.size();
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int tmp = 0;
    for(int i = 0; i < y_leng; i++) {
        string result;
        tmp = 0;
        for(int j = 0; j < x_leng; j++) {
            int a = (x[j]-'0') * (y[i]-'0') + tmp;
            tmp = 0;
            if(a >= 10) {
                tmp = (a/10);
                result.push_back((a%10)+'0');
            }
            else {
                result.push_back(a+'0');
            }
            if(j+1==x_leng && tmp!=0) {
                result.push_back(tmp+'0');
            } 
            
        }
        reverse(result.begin(),result.end());
        for(int p=0;p<i;p++) {
            result.push_back('0');
        }
        sum = bigNumAdd(sum,result);
    }
    return sum;
}