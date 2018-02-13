//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string text,pat;
        cin>>text>>pat;
        int pattext[300],patpat[300];
        for(int i=0;i<=290;i++)
        {pattext[i]=0;patpat[i]=0;}
        for(int i=0;i<pat.length();i++)
        {
            patpat[pat[i]]++;
        }
        int first=0,last=0;
        int len=INT_MAX,start,end;
        int count =0;
        while(last<text.length())
        {
            pattext[text[last]]++;
            if(pattext[text[last]]<=patpat[text[last]] and patpat[text[last]]!=0)
                count++;
            if(count==pat.length())
            {
                while(pattext[text[first]]>patpat[text[first]] or patpat[text[first]]==0)
                {
                    if(pattext[text[first]]>patpat[text[first]])
                        pattext[text[first]]--;
                    first++;
                }

                if(len>last-first)
                {
                    len=last-first;
                    start=first;
                    end=last;
                }
            }
            last++;
        }
        if(len==INT_MAX)
            {cout<<-1<<endl;continue;
        }
        for(int i=start;i<=end;i++)
        {
            cout<<text[i];
        }
        cout<<endl;
    }
}

