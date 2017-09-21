/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/
// Should reverse list and return new head.
Node* reverse(Node *head)
{
  struct Node *a=head;
  struct Node *s=NULL;
  struct Node *b;
  while(a!=NULL)
  {
      b=a->next;
      a->next=s;
      s=a;
      a=b;
  }
  return s;
}
