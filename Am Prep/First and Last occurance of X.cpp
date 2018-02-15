//https://practice.geeksforgeeks.org/problems/find-first-and-last-occurrence-of-x/0

#include<iostream>
#include<algorithm>

using namespace std;


/* Driver program to test above function */
int main()
{
	int test,*nos,n,x,count=0,flag=0;
	
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		cin >> n;
		nos = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			cin >> nos[j];
		}
		cin >> x;
		int index=find(nos, nos + n, x)-nos;
		if (index==n) 
		{
		   cout<<-1<<endl; 
		    flag=1;
		}
		int j = index+1;
		while (nos[j] == nos[index])
		{
		    count++;
		    j++;
		}
		
		if(!flag)	
		cout << index << " " << index + count << endl;
		free(nos);
		count=0;
		flag=0;
	}
}
