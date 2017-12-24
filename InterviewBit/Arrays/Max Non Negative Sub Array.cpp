// https://www.interviewbit.com/problems/max-non-negative-subarray/

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   long long int start=0, end=0, ansStart=0, length=0, ansLength=0, ansEnd=-1, cumulative_Sum = INT_MIN, cumulative_max_Sum=INT_MIN;
   int i=0;
   
   while(i<A.size()){
       if(A[i]>=0){
            start = i;
            cumulative_Sum =0;
            length =0;
            
            while(A[i]>=0 && i<A.size()){
                cumulative_Sum +=A[i];
                i++;   
            }
            end = i-1;
            
           if( ( cumulative_Sum>cumulative_max_Sum ) || ( cumulative_Sum==cumulative_max_Sum && end - start +1 < ansLength ) ){
               ansStart = start;
               ansEnd = end;
               ansLength = start + end -1 ;
               cumulative_max_Sum = cumulative_Sum;
            }
       }
       i++;
       
    }
       vector <int> ans;
       for(int i=ansStart; i<=ansEnd;i++){
           ans.push_back(A[i]);
       }
       
       return ans;
  
}
