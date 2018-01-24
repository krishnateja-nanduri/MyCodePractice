//https://www.interviewbit.com/problems/construct-binary-tree-from-inorder-and-preorder/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 TreeNode* helper(vector<int> &pre, unordered_map<int,int>& in_map, int ps, int offset,int n) {

        if(n==0)
            return NULL;
        TreeNode* root = new TreeNode(pre[ps]);
        int id = in_map[pre[ps]];
        int l = id-offset;
        root->left = helper(pre, in_map, ps+1, offset ,l);
        root->right = helper(pre, in_map, ps+l+1, offset+l+1, n-l-1);
        return root;
    }
TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = inorder.size();

        unordered_map<int, int> in_map;
        for (int i = 0; i < n; ++i) {
            in_map[inorder[i]] = i;
        }

        return helper(preorder, in_map, 0, 0 , n);
    }

    
