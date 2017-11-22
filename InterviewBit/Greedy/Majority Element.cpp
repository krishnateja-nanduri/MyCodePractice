// https://www.interviewbit.com/problems/majority-element/

int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = A[0], m_count = 1;
    
    for(int i = 1; i < A.size(); i++){
        if(A[i] == m){
            m_count++;
        }
        else{
            m_count--;
            if(m_count == 0){
                m = A[i];
                m_count = 1;
            }
        }
    }
    
    return m;
}
