/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//function Template for C++
queue<long long int> rev(queue<long long int> q)
{
    stack<long long int> s;
    while (q.size() > 0) {
        s.push(q.front());
        q.pop();
    }
    while (s.size() > 0) {
        q.push(s.top());
        s.pop();
    }
    return q;
}
