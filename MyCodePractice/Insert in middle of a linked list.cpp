/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*
Structure of the Node of the linked list is as
struct Node {
	int data;
	Node* next;
};
*/
// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x)
{
	Node* temp=head;
	Node* temp1=new Node();
	int count=0;
	while(temp!=NULL)
	{
	    count+=1;
	    temp=temp->next;
	}
	count+=1;
	count/=2;
	temp=head;
	while(--count)
	temp=temp->next;
	temp1->data=x;
	temp1->next=temp->next;
	temp->next=temp1;
	return head;
}
