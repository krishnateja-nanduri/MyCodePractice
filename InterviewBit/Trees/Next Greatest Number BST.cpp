//https://www.interviewbit.com/problems/next-greater-number-bst/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* searchNode(TreeNode* root, int B){
    if(root->val == B){
        return root;
    }
    else if(root->val < B){
        return searchNode(root->right, B);
    }
    return searchNode(root->left, B);
}
 
TreeNode* Solution::getchild(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    TreeNode* required = searchNode(A, B);
    TreeNode* prev = NULL;
    TreeNode* parent = A;
    TreeNode* child = NULL;
    
    if(required == NULL){
        return NULL;
    }
    else if(required->right != NULL){
        prev = required->right;
        TreeNode* temp = required->right;
        while(temp != NULL){
            prev = temp;
            temp = temp->left;
        }
        return prev;
    }
    else{
        while(parent != required){
            if(parent->val < B){
                parent = parent->right;
            }
            else{ // parent->val > B
                child = parent;
                parent = parent->left;
            }
        }
    }
    
    return child;
    
}
