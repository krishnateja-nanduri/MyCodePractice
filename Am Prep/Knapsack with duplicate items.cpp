//https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0

#include <bits/stdc++.h>
using namespace std;
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j;
   int K[W+1];
   // Build table K[][] in bottom up manner
   for (i = 0; i <= W; i++)
   {
       K[i]=0;
       for (j = 0; j <n; j++)
       {
           if (wt[j] <= i)
                 K[i]= max(val[j] + K[i-wt[j]],  K[i]);
       }
   }
 
   return K[W];
}
int main() {
	int tc;
	cin>>tc;
	while(tc--){
	    int n,w,i;
	    cin>>n>>w;
	    int val[n],wt[n];
	    for(i=0;i<n;i++)
            cin>>val[i];
        for(i=0;i<n;i++)
            cin>>wt[i];
        cout << knapSack(w,wt,val,n) <<endl;
	}
	return 0;
}
