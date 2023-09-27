#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
bool cmp(string a, string b) {
    if(a.size()==b.size()) {
        return a<b;
    }
    return a.size()<b.size();
}
int main() {
    int n,i=0, count = 0;
    cin >> n;
    //string word[n];
    vector<string> word2;
    map<string,int>word;
    string tmp;
    for(int i=0;i<n;i++) {
        cin >> tmp;
        word.insert({tmp,tmp.size()});
    }
    for(auto iter = word.begin() ; iter != word.end(); iter++){
        tmp = iter->first;
        word2.emplace_back(iter->first);
        i++;
	}
    sort(word2.begin(),word2.end(),cmp);

    for(int i=0;i<word2.size();i++) {
        cout << word2[i] << "\n";
    }
}