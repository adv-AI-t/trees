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
    
}