//https://www.hackerrank.com/challenges/insert-a-node-at-a-specific-position-in-a-linked-list/problem

/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
   struct Node* temp = head, *newNode = new Node();
    newNode->data = data;
    if(position == 0){
        newNode->next = temp;
        head = newNode;
        return head;
    }
    while(position-->1) temp=temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

