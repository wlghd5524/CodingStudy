#include <iostream>
using namespace std;
pair<char, char> graph[26];
void preorder(char x)
{
    if (x != '.')
    {
        cout << x;
        preorder(graph[x - 'A'].first);
        preorder(graph[x - 'A'].second);
    }
}
void inorder(char x)
{
    if (x != '.')
    {
        inorder(graph[x - 'A'].first);
        cout << x;
        inorder(graph[x - 'A'].second);
    }
}
void postorder(char x)
{
    if (x != '.')
    {
        postorder(graph[x - 'A'].first);
        postorder(graph[x - 'A'].second);
        cout << x;
    }
}
int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char parent, left, right;
        cin >> parent >> left >> right;
        graph[parent - 'A'].first = left;
        graph[parent - 'A'].second = right;
    }
    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}