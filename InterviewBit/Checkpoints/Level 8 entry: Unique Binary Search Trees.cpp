//https://www.interviewbit.com/problems/unique-binary-search-trees/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */ 
 vector<TreeNode*> genTrees(int min, int max)
        {
            vector<TreeNode*> result;
            if (max < min)
            {
                result.push_back(NULL);
                return result;
            }
            for (int i = min; i <= max; i++)
            {
                vector<TreeNode*> leftSubtrees = genTrees(min, i - 1);
                vector<TreeNode*> rightSubtrees = genTrees(i + 1, max);

                for (size_t j = 0; j < leftSubtrees.size(); j++)
                {
                    for (size_t k = 0; k < rightSubtrees.size(); k++)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = leftSubtrees[j];
                        root->right = rightSubtrees[k];
                        result.push_back(root);
                    }
                }
            }
            return result;
        }

vector<TreeNode*> Solution::generateTrees(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

      if (n == 0)
            {
                vector<TreeNode*> result;
                return result;
            }
            return genTrees(1, n);
 }

