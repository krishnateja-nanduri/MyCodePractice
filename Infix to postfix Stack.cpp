//Question : http://practice.geeksforgeeks.org/problems/infix-to-postfix/0
//
#include <stack>
#include <iostream>
using namespace std;

int precedence(char a)
{
    if(a=='^')
    return 3;
    else if(a=='/' || a=='*')
    return 2;
    else if(a=='+' || a=='-')
    return 1;
    else
    return -1;
}

void infixToPostfix(string exp)
{
    stack <char> s;
    int l=exp.length();
    string output;
    for(int i=0; i<l; i++)
    {
        if(exp[i]>='a' && exp[i]<='z' || exp[i]>='A' && exp[i]<='Z')
        {
            output=output+exp[i];
        }
        else if(exp[i]=='(')
        {
            s.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            while(!s.empty() && s.top()!='(')
            {
                char c=s.top();
                output=output+c;
                s.pop();
            }
            if(s.top()=='(')
            {
                s.pop();
            }
        }
        else
        {
            while(!s.empty() && precedence(s.top())>=precedence(exp[i]))
            {
                    char c=s.top();
                    output=output+c;
                    s.pop();
            }
            s.push(exp[i]);
        }
    }
    while(!s.empty())
    {
        char c=s.top();
        output=output+c;
        s.pop();
    }
    cout << output << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        infixToPostfix(s);
    }
	return 0;
}
