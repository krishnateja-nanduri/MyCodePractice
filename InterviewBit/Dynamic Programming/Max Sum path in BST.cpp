//https://www.interviewbit.com/problems/max-sum-path-in-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int GetMax(TreeNode *node, int& maxAcrossRoot)  
    {  
      if(node == NULL) return 0;  
      int left = GetMax(node->left, maxAcrossRoot);  
     int right = GetMax(node->right, maxAcrossRoot);  
      int cMax = node->val;  
      if(left>0)  
        cMax+=left;  
      if(right>0)  
        cMax+=right;  
      maxAcrossRoot = std::max(maxAcrossRoot, cMax);  
      return std::max(  
        node->val,   
        std::max(node->val+left, node->val+right)); 
}
int Solution::maxPathSum(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     int maxAcrossRoot=INT_MIN;  
      int maxEndByRoot = GetMax(A, maxAcrossRoot);  
      return std::max(maxAcrossRoot, maxEndByRoot);  
    }  
    

