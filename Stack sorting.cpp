/*

Question: http://practice.geeksforgeeks.org/problems/sort-a-stack/1

Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/
/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   stack<int>tmp;
   while(!s.empty())
   {
       int t=s.top();
       s.pop();
       if(tmp.empty())
       tmp.push(t);
       else{
       while(!tmp.empty()&&tmp.top()<t)
       {
           s.push(tmp.top());
           tmp.pop();
       }
       tmp.push(t);
       }
           
       }
   while(!tmp.empty())
   {
       s.push(tmp.top());
       tmp.pop();
   }
}

