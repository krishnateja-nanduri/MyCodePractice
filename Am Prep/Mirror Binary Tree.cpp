//Given a BST, show the mirror image

#include<bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node* lft;
    struct node* rt;
};
 
struct node* newNode(int data)
 
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->lft = NULL;
  node->rt = NULL;
 
  return(node);
}

void mirror(struct node* node) 
{
  if (node==NULL) 
    return;  
  else
  {
 
    struct node* tmp;
    mirror(node->lft);
    mirror(node->rt);
 
    tmp        = node->lft;
    node->lft  = node->rt;
    node->rt = tmp;
 
  }
} 
 
 
void inOrder(struct node* node) 
{
  if (node == NULL) 
    return;
 inOrder(node->lft);
  cout << node->data; 
 inOrder(node->rt);
}  

int main()
{
  struct node *root = newNode(1);
  root->lft        = newNode(2);
  root->rt       = newNode(3);
  root->lft->lft  = newNode(4);
  root->lft->rt = newNode(5); 
  root->rt->lft = newNode(6); 
  root->rt->rt = newNode(7); 
 
  cout << endl<< "Inorder traversal of the constructed tree is "<<endl;
  inOrder(root);
  mirror(root); 
  cout << endl<< "Inorder traversal of the mirrored tree is "<<endl;
  inOrder(root);
 
  return 0;  
}
