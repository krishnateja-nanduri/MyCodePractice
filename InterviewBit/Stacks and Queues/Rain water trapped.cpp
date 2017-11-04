// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   
    vector <int> left(A.size());
    vector <int> right(A.size());
    
    int leftMax=A[0], rightMax = A[A.size()-1] ;
    int ans=0;
    
    for(int i=0;i<A.size();i++){
        leftMax=max(A[i],leftMax);
        left[i]=leftMax;
    }
    
    for(int i=A.size()-1; i>=0; i--){
        rightMax=max(A[i],rightMax);
        right[i]=rightMax;
    }
    
    for(int i=0 ; i<A.size() ; i++){
        ans += min(left[i], right[i]) - A[i]; 
    }
    
    return ans;
}
