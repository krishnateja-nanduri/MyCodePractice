// https://www.interviewbit.com/problems/zigzag-level-order-traversal-bt/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void zigzag(TreeNode* A, vector<vector<int> >& soln, bool left, int level){
    if(A == NULL){
        return;
    }
    
    if(soln.size() < level){
        vector<int> temp;
        soln.push_back(temp);
    }
    
    if(left){
        soln[level-1].push_back(A->val);
    }
    else{
        soln[level-1].insert(sol[level-1].begin(), A->val);
    }
    
    zigzag(A->left, soln, !left, level+1);
    zigzag(A->right, soln, !left, level+1);
}

vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > soln;
    
    zigzag(A, soln, true, 1);
    
    return soln;
}
