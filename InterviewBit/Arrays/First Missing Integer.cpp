// https://www.interviewbit.com/problems/first-missing-integer/

int Solution::firstMissingPositive(vector<int> &A) {
    int verify = 0;
    
    for(int i=0;i<A.size();i++){
        if(A[i]>0){
            swap(A[i],A[verify]);
            verify++;
        }
    }
    
    for(int i=0;i<verify;i++){
        if( abs(A[i]) < verify && A[abs(A[i])] >0 ){
            A[abs(A[i])] = -A[abs(A[i])];
        }
    }
    
    for(int i=1;i<verify;i++){
        if(A[i]>0)
            return i;
    }
    
    return verify+1;
}
