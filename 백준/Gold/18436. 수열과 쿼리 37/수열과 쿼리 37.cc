#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int arr[100000];
vector<int> evenTree;
int makeEvenTree(int node, int start, int end)
{
    if (start == end)
    {
        if (arr[start] % 2 == 0)
        {
            return ++evenTree[node];
        }
        return evenTree[node];
    }
    int mid = (start + end) / 2;
    return evenTree[node] = makeEvenTree(node * 2, start, mid) + makeEvenTree(node * 2 + 1, mid + 1, end);
}
int evenUpdate(int node, int start, int end, int index, int value)
{
    if (index < start || index > end)
    {
        return evenTree[node];
    }
    if (start == end)
    {
        if (arr[index] % 2 == 0)
        {
            if (value % 2 == 1)
            {
                return --evenTree[node];
            }
        }
        else
        {
            if (value % 2 == 0)
            {
                return ++evenTree[node];
            }
        }
        return evenTree[node];
    }
    int mid = (start + end) / 2;
    return evenTree[node] = evenUpdate(node * 2, start, mid, index, value) + evenUpdate(node * 2 + 1, mid + 1, end, index, value);
}
int evenResult(int node, int start, int end, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    if (start >= left && end <= right)
    {
        return evenTree[node];
    }
    int mid = (start + end) / 2;
    return evenResult(node * 2, start, mid, left, right) + evenResult(node * 2 + 1, mid + 1, end, left, right);
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int treeDepth = ceil(log2(n));
    int treeSize = 1 << (treeDepth + 1);
    evenTree.resize(treeSize);
    makeEvenTree(1, 0, n - 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int cmd, a, b;
        cin >> cmd >> a >> b;
        if (cmd == 1)
        {
            evenUpdate(1, 0, n - 1, a - 1, b);
            arr[a - 1] = b;
        }
        else if (cmd == 2)
        {
            cout << evenResult(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
        else
        {
            cout << (b - a + 1) - evenResult(1, 0, n - 1, a - 1, b - 1) << "\n";
        }
    }
    return 0;
}