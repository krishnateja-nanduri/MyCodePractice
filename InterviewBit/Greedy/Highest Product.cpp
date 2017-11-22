//https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), greater<int>());
    int i = A[0]*A[1]*A[2];
    int j = A[0]*A[A.size()-1]*A[A.size()-2];
    return max(i, j);
}
