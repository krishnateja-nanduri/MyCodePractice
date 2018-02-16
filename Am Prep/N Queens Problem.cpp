//https://practice.geeksforgeeks.org/problems/n-queen-problem/0


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int chess[][100],int row,int col,int n,int col1)
{
	
	int i,j;
for(int k=0;k<col;k++)
{
    if(chess[row][k]==1)
    return false;
}

for(i=row,j=col;i>=0 && j>=0;i--,j--)
{
    if(chess[i][j]==1)
    return false;
}

for(i=row,j=col;i<n && j>=0;i++,j--)
{
    if(chess[i][j]==1)
    return false;
}
	return true;
	
}

void initialise(int x[][100],int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			x[i][j]=0;
		}
	}
}

bool queenCombo(int m[][100],int row,int col,int x)
{
	if(x==col)
	{
	    cout<<"[";
					for(int i=0;i<col;i++)
					{
						for(int j=0;j<row;j++)
						{
							if(m[j][i]==1)
							{cout<<j+1<<" ";
							break;}
						}
					}
					cout<<"] ";
				
	}
	
		for(int j=0;j<row;j++)
		{
		
			if(isSafe(m,j,x,row,col)==true)
			{
				m[j][x]=1;
				queenCombo(m,row,col,x+1);
				m[j][x]=0;	
			}
			
		}
		
	
}




int main()
{
	int m[100][100];
	
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    if(n==2||n==3)
	    cout<<"-1"<<endl;
	    else{
	    initialise(m,n,n);
	    queenCombo(m,n,n,0);
	    cout<<endl;}
	}
	
	
}
