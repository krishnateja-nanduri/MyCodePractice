//https://practice.geeksforgeeks.org/problems/rotten-oranges/0

#include <bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
       {
           int r,c;
           cin>>r>>c;
           int a[r][c];
           int i,j;
           for(i=0;i<r;i++)
               for(j=0;j<c;j++)
                  cin>>a[i][j];
           
           queue<int> q;
           for(i=0;i<r;i++)
              {
                 for(j=0;j<c;j++)
                    {
                       if (a[i][j]==2)
                          q.push(c*i+j);
                    }
              }
           
           int p=0,k,l=0;
           k=q.front(); 
           while(!q.empty())
              {
                  int d,r1,c1;
                  d=q.front();
                  r1=d/c;
                  c1=d%c;                   
                  q.pop();
                  if (d==k)
                     {
                         p=0;
                         if (a[r1-1][c1]==1 && (r1-1)>=0)
                             {
                                  if (p==0)
                                     {
                                         k=c*(r1-1)+c1;
                                         l++; 
                                         p=1;                              
                                     }
                                  q.push(c*(r1-1)+c1);
                                  a[r1-1][c1]=2;
                             }
                         if (a[r1+1][c1]==1 && (r1+1)<r)
                             {
                                  if (p==0)
                                     {
                                         k=c*(r1+1)+c1;
                                         l++; 
                                         p=1;                              
                                     }
                                  q.push(c*(r1+1)+c1);
                                  a[r1+1][c1]=2;
                             }
                         if (a[r1][c1+1]==1 && (c1+1)<c)
                             {
                                  if (p==0)
                                     {
                                         k=c*(r1)+c1+1;
                                         l++;  
                                         p=1;                             
                                     }
                                  q.push(c*(r1)+c1+1);
                                  a[r1][c1+1]=2;
                             }
                         if (a[r1][c1-1]==1 && (c1-1)>=0)
                             {
                                  if (p==0)
                                     {
                                         k=c*(r1)+c1-1;
                                         l++; 
                                         p=1;                              
                                     }
                                  q.push(c*(r1)+c1-1);
                                  a[r1][c1-1]=2;
                             }
                     }
                  else
                     {
                         if (a[r1-1][c1]==1 && (r1-1)>=0)
                             {
                                  q.push(c*(r1-1)+c1);
                                  a[r1-1][c1]=2;                                 
                             }
                         if (a[r1+1][c1]==1 && (r1+1)<r)
                             {
                                  q.push(c*(r1+1)+c1);
                                  a[r1+1][c1]=2;                                 
                             }
                         if (a[r1][c1+1]==1 && (c1+1)<c)
                             {
                                  q.push(c*(r1)+c1+1);
                                  a[r1][c1+1]=2;                                
                             }
                         if (a[r1][c1-1]==1 && (c1-1)>=0)
                             {
                                  q.push(c*(r1)+c1-1);
                                  a[r1][c1-1]=2;                                 
                             }
                     }
                                  
              }
           int flag=0;
           for(i=0;i<r;i++)
              {
                 for(j=0;j<c;j++)
                    {
                       if (a[i][j]==1)
                       {
                          flag=1;
                          break;
                       }
                    }
                  if (flag==1)
                     break;
              }
          if (flag==1)
             cout<<-1<<"\n";
          else
             cout<<l<<"\n";
       }
    return 0;
}




