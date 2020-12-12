#include<iostream>
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printInorder(struct Node *tree)
{
    stack<Node*> s;
    struct Node *curr = tree;
    // s.push(tree);
    do
    {
        if(curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            s.pop();
            cout << curr->data;
            curr = curr->right;
        }
    }while(!s.empty() || curr != NULL);
}

void printPreorder(struct Node *tree)
{
    
}

int main()
{
    struct Node *tree = new Node(4);
    tree->left = new Node(2);
    tree->left->left = new Node(1);
    tree->left->right = new Node(3);
    tree->right = new Node(6);
    tree->right->left = new Node(5);
    tree->right->right = new Node(7);
    printInorder(tree);
}