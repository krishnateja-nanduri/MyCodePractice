//https://www.hackerrank.com/challenges/the-indian-job/problem

#include<iostream>
using namespace std ;

void calculate(int arr[], int g , int n)
{
    int sum = 0 , max;
    int i, j;
   
    // Caculcate sun of all elements
    for (i = 0; i < n; i++)
      sum += arr[i];
     
   
    bool part[g+1][n+1];
  
    // initialize top row as true
    for (i = 0; i <= n; i++)
      part[0][i] = true;
       
    // initialize leftmost column, except part[0][0], as 0
    for (i = 1; i <= g; i++)
      part[i][0] = false;     
      
     // Fill the partition table in botton up manner 
     for (i = 1; i <= g; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }
    
    for(i=g;i>=0;i--){
        
        if(part[i][n]==true){
            max=i ;
            break ;
        }
    }    
    if(2*max>=sum)
        cout << "YES" << endl ;
    else
        cout << "NO"  << endl ;   
}   

  
int main(){
  int t ;
   cin >> t ;
  while(t--){
    int  n , g , i;
    cin >> n ;
    cin >> g ;
     int arr[n];
     for(i=0;i<n;i++)
      cin >> arr[i];
    calculate(arr,g,n);
  } 
}
