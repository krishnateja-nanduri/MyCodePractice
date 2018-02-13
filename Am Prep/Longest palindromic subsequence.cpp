//https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence/0

#include<bits/stdc++.h>

using namespace std;

int check(string s,int i,int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
        return 0;

        i++;
        j--;
    }

    return 1;
}

int longest_palindrome(string s)
{
    int n=s.length(),i,j,temp,max=1,a[n][n];

    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       a[i][j]=0;
    }

    for(i=0,j=0;i<n;i++,j++)
    a[i][j]=1;

    i=1;
    temp=i;

    while(temp<n)
    {
        i=temp;

        for(j=0;j<n;j++)
        {
            if(i==n)
            break;

            if(s[j]==s[i])
            {
              a[j][i]=a[j+1][i-1]+2;

              if(a[j][i]>max)
              max=a[j][i];
            }

            else
            {
                if(a[j][i-1]>a[j+1][i])
                a[j][i]=a[j][i-1];

                else
                a[j][i]=a[j+1][i];
            }

            i++;
        }

        temp++;
    }

    return max;
}

int main()
 {
    int t;
    cin>>t;
    string str;

    while(t--)
    {
        cin>>str;
        
        int result=longest_palindrome(str);
        
        cout<<result<<endl;
    }
 }
