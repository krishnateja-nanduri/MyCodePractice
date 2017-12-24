//https://www.interviewbit.com/problems/build-identical-trees/?test_id=4423

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    if(A==NULL && B==NULL) return 0;
      if(A==NULL) {
          int L=cntMatrix(A,B->left); if(L==-1) return -1;
          int R=cntMatrix(A,B->right);if(R==-1) return -1;
          return L+R+1;
      }
      if(B==NULL) return -1;
      int L=cntMatrix(A->left,B->left);   if(L==-1) return -1;
      int R=cntMatrix(A->right,B->right); if(R==-1) return -1;
      return L+R;
    }


