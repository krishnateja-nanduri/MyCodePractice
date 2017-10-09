void push(queue<int> &q,int x)
{
    //Your code here
    q.push(x);
}
/*pop out the front element 
from the queue q and returns it */
int pop(queue<int> &q)
{
   //Your code here
   int ret = -1;
   if (!q.empty())
   {
       ret = q.front();
       q.pop();
   }
   return ret;
}
/*returns the size of the queue q */
int getSize(queue<int> &q)
{
    //Your code here
    return q.size();
}
/*returns the last element of the queue */
int getBack(queue<int> &q)
{
	//Your code here
	int ret = -1;
	if (!q.empty()) 
	{
	    ret = q.back();
	}
	return ret;
	
}
/*returns the first element of the queue */
int getFront(queue<int> &q)
{
	//Your code here
	int ret = -1;
	if (!q.empty())
	{
	    ret = q.front();
	}
	return ret;
}

