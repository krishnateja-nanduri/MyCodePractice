//https://www.hackerrank.com/challenges/tree-top-view/problem

/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void left_side(node* root)
{
    if (root == NULL) return;

     left_side(root->left);
     cout<<root->data<<" ";
}

void right_side (node* root)
 {
    if (root == NULL) return;
    cout<<root->data<<" ";
    right_side(root->right);

}

void topView(node * root)
{
   if(root != NULL)
    {
   left_side( root->left);
   cout<<root->data<<" ";
   right_side( root->right);
   }

}

