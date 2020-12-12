#include<iostream>

using namespace std;

struct node
{
    int data;
    struct node *left, *right;
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printInorder(struct node *tree)
{
    if(tree == NULL)
        return;
    else
    {
        printInorder(tree->left);
        cout << tree->data;
        printInorder(tree->right);
    }
}

void printPostorder(struct node *tree)
{
    if(tree == NULL)
        return;
    else
    {
        printPostorder(tree->left);
        printPostorder(tree->right);
        cout << tree->data;
    }
}

void printPreorder(struct node *tree)
{
    if(tree == NULL)
        return;
    else
    {
        cout << tree->data;
        printPreorder(tree->left);
        printPreorder(tree->right);
    }
}

int main()
{
    struct node *tree = new node(4);
    tree->left = new node(2);
    tree->left->left = new node(1);
    tree->left->right = new node(3);
    tree->right = new node(6);
    tree->right->left = new node(5);
    tree->right->right = new node(7);
    printInorder(tree);
    cout << "\n";
    printPostorder(tree);
    cout << "\n";
    printPreorder(tree);
}