#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Node
{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* minVal(Node* root)
{
    Node* temp = root;

    while(temp -> left != NULL)
    {
        temp = temp -> left;
    }
    return temp;
}

Node * maxVal(Node* root)
{
    Node * temp = root;
    while(temp -> right != NULL)
    {
        temp = temp -> right;
    }
    return temp;
}


Node* insertIntoBST(Node* root, int d)
{
    //base case
    if(root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        //insert into right part
        root -> right = insertIntoBST(root -> right, d);
    }
    else
    {
        //insert into left part
        root -> left = insertIntoBST(root -> left, d);
    }
    return root;
}

Node * deleteFromBST(Node * root, int val)
{
    //base case
    if(root == NULL)
    {
        return root;
    }

    if(root -> data == val)
    {
        //0 child
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root -> left != NULL && root -> right == NULL)
        {
            Node * temp = root -> left;
            delete root;
            return temp;
        }
        //right child
        if(root -> left == NULL && root -> right != NULL)
        {
            Node * temp = root -> right;
            delete root;
            return temp;
        }

        //2 child
        //Either left me se max value lo or right me se min value lo
        //here, minval from left
        if(root -> left != NULL && root -> right != NULL)
        {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }

    else if(root -> data > val)
    {
        root -> left  = deleteFromBST(root -> left, val);
        return root;
    }
    else
    {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }

    return root;
}

void takeInput(Node* & root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node * root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node * temp = q.front();
        
        q.pop();

        if(temp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }

        else
        {
            cout << temp -> data << " ";
            
            if(temp -> left)
            {
                q.push(temp -> left);
            }

            if(temp -> right)
            {
                q.push(temp -> right);
            }
        }
    }
}

void inorder(Node * root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node * root)
{
    //base case
    if(root == NULL)
    {
        return;
    }

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node * root)
{
   //base case
    if(root == NULL)
    {
        return;
    }

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    Node * root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    cout << endl << "Printing inorder: " << endl;
    inorder(root);

    cout << endl << "Printing preorder: " << endl;
    preorder(root);

    cout << endl << "Printing postorder: " << endl;
    postorder(root);

    cout << "Min Value is " << minVal(root) -> data << endl;
    cout << "Max Value is " << maxVal(root) -> data << endl;

    //Deleting a node
    root = deleteFromBST(root, 50);

    cout << "Printing the BST: " << endl;
    levelOrderTraversal(root);

    cout << endl << "Printing inorder: " << endl;
    inorder(root);

    cout << endl << "Printing preorder: " << endl;
    preorder(root);

    cout << endl << "Printing postorder: " << endl;
    postorder(root);

    cout << "Min Value is " << minVal(root) -> data << endl;
    cout << "Max Value is " << maxVal(root) -> data << endl;

    return 0;
}