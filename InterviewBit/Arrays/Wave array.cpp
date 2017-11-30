// https://www.interviewbit.com/problems/wave-array/

vector<int> Solution::wave(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    sort(A.begin(), A.end());
    
    vector <int> soln;
    
    for(int j=1; j<A.size(); j=j+2){
       soln.push_back(A[j]);
       soln.push_back(A[j-1]);
    }
    
    if(A.size()%2==1)
        soln.push_back(A[A.size()-1]);
    
    return soln;
}
