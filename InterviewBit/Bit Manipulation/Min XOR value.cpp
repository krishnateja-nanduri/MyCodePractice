//https://www.interviewbit.com/problems/min-xor-value/

int Solution:: findMinXor(vector<int> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


 sort(A.begin(),A.end());
 int mine=INT_MAX;

 for(int i=0;i<A.size()-1;i++){
     mine=min(mine,A[i]^A[i+1]); 
 }
 return mine; 
}
