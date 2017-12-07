//https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/
int getCount(Node* head)
{
  Node* current = head;
  int count = 0;

  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count;
}

int getNode(int d, Node* head1, Node* head2)
{
  int i;
  Node* current1 = head1;
  Node* current2 = head2;

  for(i = 0; i < d; i++)
  {
    if(current1 == NULL)
    {  return -1; }
    current1 = current1->next;
  }

  while(current1 !=  NULL && current2 != NULL)
  {
    if(current1 == current2)
      return current1->data;
    current1= current1->next;
    current2= current2->next;
  }

  return -1;
}

int FindMergeNode(Node *headA, Node *headB)
{
    // Complete this function
    // Do not write the main method. 
    int c1 = getCount(headA);
  int c2 = getCount(headB);
  int d;

  if(c1 > c2)
  {
    d = c1 - c2;
    return getNode(d, headA, headB);
  }
  else
  {
    d = c2 - c1;
    return getNode(d, headB, headA);
  }
}
