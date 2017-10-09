/*
Question: http://practice.geeksforgeeks.org/problems/closest-neighbor-in-bst/

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
int findMaxforN(Node* root, int N)
{
	Node* tmp;
	tmp = root;
	
	while (tmp != NULL) {
	    if (N == tmp->key) 
	    {
	        return N;
	    }
	    if (tmp->key > N) 
	    {
	        tmp = tmp->left;
	    }
	    else if (tmp->key < N) 
	    {
	        if (tmp->right != NULL && tmp->right->key < N) 
	        {
	            tmp = tmp->right;   
	        }
	        else 
	        {
	            return tmp->key;
	        }
	    }
	}
	return -1;
}
