#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node
{
    public:
    int data;
    node * right;
    node * left;

    node(int d)
    {
        this -> data  = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node * buildTree(node * root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1)
    {
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root -> right = buildTree(root -> right);
    return root;
}

void inorder(node * root)
{
    stack<node*> st;
    node * curr = root;

    while(curr != NULL || !st.empty())
    {
        while(curr != NULL)
        {
            st.push(curr);
            curr = curr -> left;
        }

        curr = st.top();
        st.pop();
        cout << curr -> data << " ";

        curr = curr -> right;
    }
}

int main()
{
    node * root = NULL;

    //creating a tree
    root = buildTree(root);

    //1 3 7 -1 -1 9 -1 -1 5 11 -1 -1 13 -1 -1 

    cout << "Inorder Traversal: " << endl;
    inorder(root);
    cout << endl;

    return 0;
}