/*
Question: http://practice.geeksforgeeks.org/problems/pairwise-consecutive-elements/1

Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
// your task is to complete the function
// function should return true/false or 1/0
bool pairWiseConsecutive(stack<int> s)
{
    int a, b;
    while(!s.empty())
    {
        a = s.top();
        s.pop();
        
        if(s.empty())       
            break;
        
        b = s.top();
        s.pop();
        
        if(abs(a - b) != 1)
            return false;
    }
    
    return true;
}
