// https://www.interviewbit.com/problems/max-sum-without-adjacent-elements/

int Solution::adjacent(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    if(A.size() == 0){
        return 0;
    }
    
    int incl = 0, excl = 0;
    
    for(int i = 0; i < A[0].size(); i++){
        int num = max(A[0][i], A[1][i]);
        
        int tmp = max(excl, incl);
    
        incl = excl + num;
        excl = tmp;
    }
    
    
    return max(incl, excl);
}
