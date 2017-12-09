//https://www.hackerrank.com/challenges/binary-search-tree-insertion/problem

/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/


node * insert(node * root, int value) {

 if(!root) 
    {
        root = new node();
        root->data = value;
        return root;
    }
    if(value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

