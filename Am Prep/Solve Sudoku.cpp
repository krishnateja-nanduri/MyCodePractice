//https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0

#include <iostream>
using namespace std;

bool is_safe(int sudoku[][9],int row,int col,int val)
{

for(int i=0;i<9;i++)
{
    if(sudoku[row][i]==val)
    return false;
}
for(int i=0;i<9;i++)
{
    if(sudoku[i][col]==val)
    return false;
}

for(int i=(row/3)*3;i<(row/3)*3+3;i++)
{
    for(int j=(col/3)*3;j<(col/3)*3+3;j++)
    if(sudoku[i][j]==val)
    return false;
}
return true;
}

bool find_next(int sudoku[9][9],int &row,int& col)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
         if(sudoku[i][j]==0)
         {
             row=i;
             col=j;
             return true;
         }
        }
    }
    return false;
}

bool fun(int sudoku[][9])
{
    int row,col;
    if(find_next(sudoku,row,col)==false)
    return true;
    
    for(int i=1;i<=9;i++)
    {
        if(is_safe(sudoku,row,col,i))
        {
        sudoku[row][col]=i;
        if(fun(sudoku))
        return true;
        sudoku[row][col]=0;
        }
    }
    return false;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int sudoku[9][9];
	    for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        cin>>sudoku[i][j];
	    }
	    
	    fun(sudoku);
	     for(int i=0;i<9;i++)
	    {
	        for(int j=0;j<9;j++)
	        cout<<sudoku[i][j]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
