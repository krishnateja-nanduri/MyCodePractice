// https://www.interviewbit.com/problems/least-common-ancestor/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode* soln(TreeNode* root, int a, int b){
    if(root==NULL)
        return NULL;
    
    if(root->val == a || root->val == b){
        return root;
    }
    
    TreeNode* L = soln(root->left, a, b);
    TreeNode* R = soln(root->right, a, b);
    
    if(L&&R)
        return root;
        
    return L ? L : R;
    
}

bool find(TreeNode* root, int val){
    if(root==NULL)
        return false;
    
    if(root->val == val)
        return true;
        
    return find(root->left, val) || find(root->right, val) ;
}

int Solution::lca(TreeNode* A, int a, int b) {
    if(find(A, a) ==NULL || find(A, b) ==NULL)
        return -1;
        
    if(soln(A, a, b) !=NULL){
        return soln(A, a, b)->val;
    }
    
    return -1;
}
