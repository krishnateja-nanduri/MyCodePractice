//https://www.interviewbit.com/problems/spiral-order-matrix-i/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	int T=0,B,L=0,R,dir=0,i,j;
	B=A.size()-1;
	R=A[0].size()-1;
	while(T<=B && L<=R)
	{ if(dir==0){
	    for(i=L;i<=R;i++)
	    cout<<A[T][i]<<" ";
	    T++;
	    dir=1;
	           }
	   else if(dir==1)
	   { for(i=T;i<=B;i++)
	        cout<<A[i][R]<<" ";
	            R--;
	            dir=2;
	   }
	   else if(dir==2)
	   {    for(i=R;i>=L;i--)
	            cout<<A[B][i]<<" ";
	            B--;
	            dir=3;
	    }
	    else if(dir==3) {
	            for(i=B;i>=T;i--)
	            cout<<A[i][L]<<" ";
	            L++;
	            dir=0;
	    }
	}
	
	// DO STUFF HERE AND POPULATE result
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
