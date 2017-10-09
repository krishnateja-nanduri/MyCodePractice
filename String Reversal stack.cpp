/*

Question : http://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/

void reverse(char *str, int len)
{
    stack<char> string;
    for(int i=0;i<len;i++)
        string.push(str[i]);
        int i=0;
    while(!string.empty())
    {
      str[i++]=string.top();
        string.pop();
    }
}
