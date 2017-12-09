//https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>

void LevelOrder(node * root)
{
    queue<node*> nodes;
    if (root) nodes.push(root);
    for (; !nodes.empty(); nodes.pop())
    {
        cout<<nodes.front()->data<<' ';
        if (nodes.front()->left) nodes.push(nodes.front()->left);
        if (nodes.front()->right) nodes.push(nodes.front()->right);
    }
}
