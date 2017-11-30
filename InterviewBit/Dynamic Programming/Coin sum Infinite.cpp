// https://www.interviewbit.com/problems/coin-sum-infinite/

int Solution::coinchange2(vector<int> &A, int B) {

    int combos[B+1];
    memset(combos, 0, sizeof(combos));
    
    combos[0] = 1;
    
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            combos[j] = combos[j] + combos[j-A[i]];
            combos[j] = combos[j]%1000007;
        }
    }
    
    return combos[B];
}
