//https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x/0

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int test;
	cin>>test;

	while(test--){
	long n,sum;
	cin>>n>>sum;

	long arr[n];
	for(long i=0;i<n;i++)
		cin>>arr[i];

	sort(arr,arr+n);
	int count = 0,count1 = 0;
	for(long i=0;i<n-2;i++)
	{
		if(arr[i]>sum)
			break;
		for(long j=i+1;j<n-1;j++)
		{
			if(arr[i]+arr[j]>sum)
				break;
			for(long k=j+1;k<n;k++)
			{
				count1 = arr[i] + arr[j] + arr[k];
				if(count1<sum)
					count++;
				else
					break;
			}
		}
	}

	cout<<count<<endl;
}
	return 0;
}
