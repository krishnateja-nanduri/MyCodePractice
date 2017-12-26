//https://www.interviewbit.com/problems/minimum-characters-required-to-make-a-string-palindromic/

int Solution::solve(string A) {

    int n = A.size(), match = 1;
    
    if(n == 0){
        return 0;
    }
    
    for(int i = 1; i < n; i++){
        int start = 0, end = i, palin = 1;
        while(start < end){
            if(A[start] != A[end]){
                palin = 0;
                break;
            }
            start++;
            end--;
        }
        
        if(palin){
            match = i + 1;
        }
    }
    
    return n - match; 
}
