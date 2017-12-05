//https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct node{
    TreeNode* root;
    int space;
};

void make(map<int, vector<int> >& vec1, queue<node>& q){
    if(q.size() == 0){
        return;
    }
    
    TreeNode* root = (q.front()).root;
    int space = (q.front()).space;
    
    if(!root){
        return;
    }
    
    m[space].push_back(root->val);
    
    q.pop();
    
    if(root->left){
        node l1;
        l1.root =  root->left;
        l1.space = space-1;
        q.push(l1);
    }
    
    if(root->right){
        node l1;
        l1.root =  root->right;
        l1.space = space+1;
        q.push(l1);
    }
    
    make(vec1, q);
}

vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    map<int, vector<int> > vec1;
    vector<vector<int> > sol;
    queue<node> q;
    
    node n;
    n.root = A;
    n.space = 0;
    
    q.push(n);
    
    make(vec1, q);
    
    map<int, vector<int> > :: iterator it = vec1.begin();
    
    int curr = 0;
    
    while(it != vec1.end()){
        vector<int> temp;
        sol.push_back(temp);
        
        temp = it->second;
        
        for(int i = 0; i < temp.size(); i++){
            sol[curr].push_back(temp[i]);
        }
        
        curr++;
        it++;
    }
    
    return sol;
}
