#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node(int iValue) : value(iValue), left(NULL), right(NULL) {}
};

Node* insert(Node* pRoot, int value) 
{
    if (!pRoot)
        return new Node(value);
    if (value < pRoot->value)
        pRoot->left = insert(pRoot->left, value);
    else
        pRoot->right = insert(pRoot->right, value);
    return pRoot;
}

void postorder(Node* pRoot)
{
    if (!pRoot)
        return;
    postorder(pRoot->left);
    postorder(pRoot->right);
    cout << pRoot->value << "\n";
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    Node* root = nullptr;
    int value;

    while (cin >> value)
    {
        root = insert(root, value);
    }

    postorder(root);

    return 0;
}
