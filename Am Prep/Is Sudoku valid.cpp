//https://practice.geeksforgeeks.org/problems/is-sudoku-valid/0

#include <iostream>
#define N 9
using namespace std;
bool solveSudoko(int[N][N]);
void findPos(int[N][N],int&,int&);
bool isSafe(int[N][N],int,int,int);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int mat[N][N];
	    for(int i=0;i<N;i++)
	        for(int j=0;j<N;j++)
	            cin>>mat[i][j];
	    if(solveSudoko(mat))
	        cout<<"1"<<endl;
	    else
	        cout<<0<<endl;
	}
	return 0;
}
bool solveSudoko(int mat[N][N])
{
    int r,c;
    findPos(mat,r,c);
    if(r==-1&&c==-1)
        return true;
    for(int i=1;i<=N;i++)
    {
        if(isSafe(mat,r,c,i))
        {
            mat[r][c]=i;
            if(solveSudoko(mat))
                return true;
            mat[r][c]=0;
        }
    }
    return false;
}
void findPos(int mat[N][N],int& r,int &c)
{
    for(r=0;r<N;r++)
        for(c=0;c<N;c++)
            if(mat[r][c]==0)
                return;
    r=-1,c=-1;
    return;
}
bool isSafe(int mat[N][N],int r,int c,int num)
{
    for(int i=0;i<N;i++)
        if(mat[i][c]==num||mat[r][i]==num)
            return false;
    int rs=r-r%3,cs=c-c%3;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(mat[rs+i][cs+j]==num)
                return false;
    return true;
}
