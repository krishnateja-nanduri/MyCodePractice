//https://www.interviewbit.com/problems/length-of-longest-subsequence/

/*int func(const vector<int>& A, int curr, int last, int len, bool incr){
    int n = A.size();
    if(curr == n){
        return len;
    }
    
    int ans = len;
    
    for(int i = curr; i < n; i++){
        if(incr){
            if(A[i] > last){
                ans = max(ans, func(A, i+1, A[i], len+1, incr));    
            }
            else if(A[i] < last){
                ans = max(ans, func(A, i+1, A[i], len+1, false));
            }
        }
        else{
            if(A[i] < last){
                ans = max(ans, func(A, i+1, A[i], len+1, incr));    
            }
        }
    }
    
    return ans;
}*/

int Solution::longestSubsequenceLength(const vector<int> &A) {
    if(A.size() == 0){
        return 0;
    }
    
    // Recursive solution
    // return func(A, 1, A[0], 1, true);
    
    // DP solution
    int n = A.size(), sol = 1;
    
    vector<int> incr(n, 1);
    vector<int> decr(n, 1);
    vector<int> ans(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(A[i] > A[j]){
                incr[i] = max(incr[i], incr[j]+1);
                ans[i] = max(ans[i], incr[i]);
            }
            else if(A[i] < A[j]){
                decr[i] = max(decr[i], decr[j]+1);
                ans[i] = max(ans[i], max(decr[i], ans[j]+1));
            }
        }
        sol = max(sol, ans[i]);
    }

    return sol;
}
