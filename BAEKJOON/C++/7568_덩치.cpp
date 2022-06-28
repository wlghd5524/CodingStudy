#include <iostream>
using namespace std;
struct Size 
{
    int height;
    int weight;
    int k;
};

int main() {
    int n;
    cin >> n;
    struct Size size[n];
    for(int i = 0; i<n; i++) {
        size[i].k = 1;
        cin >> size[i].weight >> size[i].height;
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(size[i].height < size[j].height && size[i].weight < size[j].weight) {
                size[i].k++;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << size[i].k << " ";
    }

    return 0;
}