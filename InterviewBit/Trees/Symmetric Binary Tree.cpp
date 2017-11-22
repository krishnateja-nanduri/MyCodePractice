// https://www.interviewbit.com/problems/symmetric-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int SymTest(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return 1;
    }
    else if((left == NULL && right != NULL) || (left != NULL && right == NULL)){
        return 0;
    }
    else if(left->val == right->val){
        return min(SymTest(left->left, right->right), SymTest(left->right, right->left));
    }
    return 0;
} 

int SymmetricTest(TreeNode* root){
    if(root == NULL){
        return 1;
    }
    return SymTest(root->left, root->right);
} 

int Solution::isSymmetric(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    return SymmetricTest(A);
}
