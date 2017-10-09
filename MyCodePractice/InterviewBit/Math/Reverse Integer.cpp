//https://www.interviewbit.com/problems/reverse-integer/

int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long int soln = 0;
    
    while(A != 0){
        soln = soln*10 + (A%10);    
        A = A/10;
    }
    
    if(soln > INT_MAX || soln < INT_MIN){
        return 0;
    }
    
    return (int)soln;
}
