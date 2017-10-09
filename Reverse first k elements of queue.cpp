/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


//User function Template for C++
queue<ll> modifyQueue(queue<ll> q, int k)
{
    stack<ll> stk;
    for (int i = 0; !q.empty() && i < k; ++i) {
        stk.push(q.front());
        q.pop();
    }
    for (int i = 0; !stk.empty() && i < k; ++i) {
        q.push(stk.top());
        stk.pop();
    }
    for (int i = 0; i < q.size() - k; ++i) {
        q.push(q.front());
        q.pop();
    }
    return q;
}
