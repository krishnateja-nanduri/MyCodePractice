// https://www.interviewbit.com/problems/sum-of-fibonacci-numbers/

int Solution::fibsum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> v1;
    
    v1.push_back(1);
    v1.push_back(1);
    
    int fib, i = 2;
    
    while(fib <= A){
        fib = v1[i-2] + v1[i-1];
        v1.push_back(fib);
        i++;
    }
    
    int j = v1.size()-1;
    int sol = 0;
    
    LOOP:while(A && j >= 0){
        if(v1[j] == A){
            sol++;
            return sol;
        }
        else if(v1[j] < A){
            sol++;
            A = A - v1[j];
            goto LOOP;
        }
        j--;
    }
    
    return 0;
}
