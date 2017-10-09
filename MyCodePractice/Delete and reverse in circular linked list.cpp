/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* structure for a node 
struct Node
{
	int data;
	struct Node *next;
};
*/
/* Function to delete a given node from the list */
void deleteNode(struct Node *head, int key)
{
// Your code goes here
Node *t = head;
Node *p = head;
while(t->data != key)
{
    p=t;
    t = t->next;
}
p->next = t->next;
t->next = NULL;
}
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref)
{
// Your code goes here
    Node *t=*head_ref;
    int c;
    stack<int> s;
    while (t!=*head_ref)
    {
        c++;
        s.push(t->data);
        t = t->next;
    }
    while (!s.empty())
    {
        cout<<s.top()<<"\t";
        s.pop();
        
    }
    
}
