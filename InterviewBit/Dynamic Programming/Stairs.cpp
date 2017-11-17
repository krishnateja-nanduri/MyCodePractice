// https://www.interviewbit.com/problems/stairs/

int climb(int n){
    if(n < 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }
    return climb(n-2) + climb(n-1);
}

int Solution::climbStairs(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    return climb(A);
}
