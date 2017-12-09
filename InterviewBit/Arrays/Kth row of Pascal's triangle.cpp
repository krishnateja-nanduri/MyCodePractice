//https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/

int K(int line, int i){
    if(i == 0){
        return 1;
    }
    return K(line, i-1)*(line-i+1)/i;
}

vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> soln;

    if(A == 0){
        soln.push_back(1);
        return soln;
    }
    
    for(int i = 0; i <= A; i++){
        soln.push_back(K(A, i));    
    }
    
    return soln;
    
}
