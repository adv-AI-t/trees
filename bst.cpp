#include<iostream>
#include<stack>
using namespace std;

class Node
{
    Node* left, *right;
    int data;
    friend class Tree;

    public:
    Node()
    {
        left = right = NULL;
        data = 0;
    }
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};

class Tree
{
    Node* root;

    public:
    Tree()
    {
        root = NULL;
    }

    void add(int data)
    {
        Node* newnode = new Node(data);
        if(!root)
        {
            root = newnode;
            return;
        }
        Node* ptr = root;
        Node* parent = NULL;
        while(ptr)
        {
            parent = ptr;
            if(data<ptr->data)
            ptr = ptr->left;
            else
            ptr = ptr->right;
        }
        if(data<parent->data)
        parent->left = newnode;
        else
        parent->right = newnode;
    }

    void inorderNonrecursive()
    {
        stack<Node*>s1;
        Node* temp = root;
        while(temp || !s1.empty())
        {
            while(temp)
            {
                s1.push(temp);
                temp = temp->left;
            }
            temp = s1.top();
            cout<<temp->data<<" ";
            s1.pop();
            temp = temp->right;
        }
    }

    void inorder(Node* root)
    {
        if(!root) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void inorderhelper()
    {
        inorder(root);
    }
};

int main()
{
    Tree t1;
    t1.add(5);
    t1.add(3);
    t1.add(7);
    t1.inorderNonrecursive();
    return 0;
}