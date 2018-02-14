//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

#include <iostream>
#include<queue>
using namespace std;
class compare
{
public:
    bool operator()(const int&a, const int &b)
    {
        return a>b;
    }
};
int main()
{
    priority_queue <int> Max;
    priority_queue <int, vector<int>, compare> Min;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(Max.size()==0)
        {
            Max.push(x);
        }
        else if(Max.top()<=x)
        {
            Min.push(x);
        }
        else if(Max.top()>x)
        {
            Max.push(x);
        }
        if(Min.size()>Max.size())
        {
            Max.push(Min.top());
            Min.pop();
        }
        if((Max.size()-Min.size())>1)
        {
            Min.push(Max.top());
            Max.pop();
        }
         if(Max.size()==Min.size())
         {
             cout<<(Max.top()+Min.top())/2<<endl;
         }
         else
         {
            cout<<Max.top()<<endl;
         }
    }
    return 0;
}

