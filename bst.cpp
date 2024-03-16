#include<iostream>
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
};