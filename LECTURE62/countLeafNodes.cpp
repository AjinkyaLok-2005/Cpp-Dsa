#include<iostream>
#include<queue>
using namespace std;

class node
{
    public:
    int data;
    node * left;
    node * right;

    node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node * buildTree(node * root)
{
    cout << "Enter the data: " <<endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting to the left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting to the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void inorder(node * root, int & count)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left, count);

    //leaf node
    if(root -> left == NULL && root -> right == NULL)
    {
        count++;
    }

    inorder(root -> right, count);
}

int noOfLeafNodes(node * root)
{
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main()
{
    node * root = NULL;

    //creating a tree
    root = buildTree(root);

    //20 10 5 -1 -1 15 13 -1 -1 -1 35 30 -1 -1 42 -1 -1 

    int ans = noOfLeafNodes(root);

    cout << "Number of leaf nodes are: " << ans << endl;

    return 0;
}