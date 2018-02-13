//https://practice.geeksforgeeks.org/problems/maximum-sum-rectangle/0

#include<bits/stdc++.h>
using namespace std;

int sum(vector<int> a, int& maxup, int &maxdown)
{
    int cursum = 0;
    int ans = 0;
    int start = 0;
    
    for(int i=0;i<a.size();i++)
    {
        cursum += a[i];
        
        if(cursum < 0)
        {
            cursum = 0;
            start = i+1;
        }
        
        if(cursum > ans)
        {
            ans = cursum;
            maxup = start;
            maxdown = i;
        }
    }
    
    return ans;
}

void print(vector<int> a, int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int findMax(vector<vector<int>> a, int n, int m)
{
    int maxsum = INT_MIN;
    int maxleft;
    int maxright;
    int maxup;
    int maxdown;
    
    for(int left=0;left<m;left++)
    {
        vector<int> dp(n, 0);
        for(int right=left;right<m;right++)
        {
            for(int i=0;i<n;i++)
            {
                dp[i] += a[i][right]; 
            }
            
           // print(dp, n);
            
            int s = sum(dp, maxup, maxdown);
           // cout<<s<<endl;
            if(s > maxsum)
            {
                maxsum = s;
                maxleft = left;
                maxright = right;
            }
        }
    }
    
    return maxsum;
}

int main()
 {
    int t;
    cin >> t;
    
    while(t--)
    {
        int n, m;
        cin >> n >> m;
    
        vector<vector<int>> a(n, vector<int>(m));
    
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> a[i][j];
        
        cout<<findMax(a, n, m)<<endl;
    }
	//code
	return 0;
}
