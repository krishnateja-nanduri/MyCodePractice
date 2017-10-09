/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/
// function should return the sum of all 
// left leaf nodes
int sum=0;
void leftsum(Node*root)
{
     if(root==NULL)
        return;
    leftsum(root->left);
    if(root->left!=NULL && root->left->left==NULL && root->left->right==NULL)
    sum+=root->left->data;
    leftsum(root->right);
}
int leftLeafSum(Node* root)
{
   sum=0;
   leftsum(root);
   return sum;
}

