#include <iostream>
#include <vector>
#include <math.h>
#define MAX 1000000
using namespace std;
long long int arr[MAX];
vector<long long int> segmentTree;
long long int update(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
    {
        return segmentTree[node];
    }
    if (start == end)
    {
        return segmentTree[node] += value;
    }
    int mid = (start + end) / 2;
    return segmentTree[node] = update(node * 2, start, mid, index, value) + update(node * 2 + 1, mid + 1, end, index, value);
}
long long int sum(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start >= left && end <= right)
    {
        return segmentTree[node];
    }
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    segmentTree.resize(treeSize);
    for (int i = 0; i < q; i++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            update(1, 0, n - 1, a - 1, b);
            arr[a - 1] += b;
        }
        else
        {
            cout << sum(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
    }
    return 0;
}