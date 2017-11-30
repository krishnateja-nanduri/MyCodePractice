// https://www.interviewbit.com/problems/excel-column-number/

int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int soln=0;
    int product=1;
    for(int i=A.length()-1; i>=0; i--){
        soln += (A[i]-'A' + 1)*product;
        product*=26;
    }
    return soln;
}
