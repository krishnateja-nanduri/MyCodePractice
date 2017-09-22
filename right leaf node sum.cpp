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
// right leaf nodes
int sum=0;
void rightsum(Node*root)
{
    if(root==NULL)
    return;
    rightsum(root->left);
    if(root->right!=NULL)
    {
        if(root->right->left==NULL && root->right->right==NULL)
        sum+=root->right->data;
    }
    rightsum(root->right);
}
int rightLeafSum(Node* root)
{
    sum=0;
    rightsum(root);
    return sum;
}
