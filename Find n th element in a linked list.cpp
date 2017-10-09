 /*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the node is
struct node
{
    int data;
    struct node *next;
};*/
int fractional_node(struct node *head, int k)
{
     int n =0;
     struct node *pos ;
     
     pos= head ;
     while(pos != NULL) 
     {   
         
         pos = pos->next ;
         n++ ;
     }
     
     int nodeNo = ceil((float)n/k);
     
     pos = head ;
     for( int i=1 ; i<nodeNo ; i++)
     {
         pos=pos->next ;
         
     }
     return pos->data ;
}
