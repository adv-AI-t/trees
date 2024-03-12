#include<iostream>
using namespace std;

class Node
{
    public:
    Node* left;
    bool lthread;
    int data;
    bool rthread;
    Node* right;

    Node()
    {
        left = right = NULL;
        data = 0;
        lthread = rthread = false;
    }
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
        lthread = rthread = false;
    }
};

class Tree
{
    Node* root;
    public:

    Tree(int data)
    {
        Node* root = new Node(data);
    }

    void insert(int value)
    {
        Node* ptr = root;
        Node* parent = NULL;
        while(ptr)
        {
            parent = ptr;
            if(value<ptr->data)
            {
                if(!ptr->lthread)
                ptr = ptr->left;
                else
                break;
            }
            else
            {
                if(!ptr->rthread)
                ptr = ptr->right;
                else
                break;
            }
        }
        Node* newnode = new Node(value);
        if(!parent)
        {
            root = newnode;
            return;
        }
        if(value<parent->data)
        {
            newnode->left = parent->left;
            newnode->lthread = parent->lthread;
            parent->lthread = false;
            parent->left = newnode;
            newnode->right = parent;
            newnode->rthread = true;
        }
        else
        {
            newnode->right = parent->right;
            newnode->rthread = parent->rthread;
            parent->right = newnode;
            parent->rthread = false;
            newnode->left = parent;
            newnode->lthread = true;
        }
    }

    Node* leftmostNode(Node* root)
    {
        Node* temp = root;
        while(temp->left&&!temp->lthread)
        temp = temp->left;
        return temp;
    }

    Node* inorder()
    {
        if(!root->right)
        return NULL;
        Node* temp = root;
        temp = leftmostNode(temp);
        while(temp)
        {
            cout<<temp->data<<" ";
            if(temp->rthread)
            temp = temp->right;
            else
            temp = leftmostNode(temp->right);
        }
        return temp;
    }
    
};

int main()
{
    Tree t1(5);
    t1.insert(3);
    t1.insert(7);
    t1.inorder();
    return 0;
}