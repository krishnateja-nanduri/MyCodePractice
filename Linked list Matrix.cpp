/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*structure of the node of the linked list is as
struct Node
{
	int data;
	Node* right, *down;
};*/
// n is the size of the matrix
// function must return the pointer to the first element 
// of the in linked list i.e. that should be the element at arr[0][0]
Node* node(int x){
    Node* node= new Node;
    node->data = x;
    node->right = node->down = NULL;
    return node;
}
Node* constructLinkedMatrix(int mat[MAX][MAX], int n)
{
    // code here
    Node* head = node(mat[0][0]);
    Node* tmp = head,*tmp2;
    for(int i=0; i<n; i++){
        tmp2 = tmp;
        for(int j=1; j<n; j++){
            tmp->right = node(mat[i][j]);
            tmp = tmp->right;
        }
        if (i<n-1){
        tmp2->down = node(mat[i+1][0]);
        tmp = tmp2->down;
        //cout<<tmp->data;
        }
    }
    return head;
}
