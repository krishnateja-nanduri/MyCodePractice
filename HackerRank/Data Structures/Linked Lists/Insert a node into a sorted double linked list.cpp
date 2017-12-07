//https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem

/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/
Node* SortedInsert(Node *head,int data)
{
    // Complete this function
   // Do not write the main method. 
   Node *newNode = (Node*) malloc(sizeof(Node));
   newNode->data = data; 
   if(head == NULL) {
       newNode->next = NULL; 
       newNode->prev = NULL;
       return newNode;
   }
   if(head->data >= newNode->data) {
       newNode->next = head; 
       newNode->prev = NULL; 
       head->prev = newNode; 
       head = newNode;
   } else {
       Node *current = head;
       while(current->next != NULL && current->next->data < newNode->data) {
           current = current->next;
       }
       newNode->prev = current;
       newNode->next = current->next;
       if(current->next != NULL) {
           current->next->prev = newNode;
       }
       current->next = newNode; 
   } 
   return head;
}

