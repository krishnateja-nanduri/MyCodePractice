//https://www.hackerrank.com/challenges/tree-huffman-decoding/problem

/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

void decode_huff(node * root,string s)
{
	node* np=root;
	for(int i=0;i<s.size();i++)
 	{
		int n= s[i] - '0';
		if(n==0) 
		{
			np=np->left;
			if(np->left ==nullptr && np->right==nullptr)
			 {
				cout<<np->data;
				np=root;
			 }
		}
		else 
		{
			np=np->right;
			if(np->left ==nullptr && np->right==nullptr) 
			{
				cout<<np->data;
				np=root;
			}
		}
	}
}
