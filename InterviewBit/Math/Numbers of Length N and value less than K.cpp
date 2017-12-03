//https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
//*********************************************************************************

vector <int> numToVec(int N) {   
    vector<int> dgt;
    while(N != 0) {
        dgt.push_back(N % 10);
        N = N / 10;
    }
    if(dgt.size() == 0)
        dgt.push_back(0);

    reverse(dgt.begin(), dgt.end());
    return dgt; 
}

int Solution:: solve(vector<int> &A, int B, int C) {
    vector<int> dgt;
    int  d, d2;
    // Convert number to dgt array
    dgt = numToVec(C);
    d = A.size();

    //Case 1
    if(B > dgt.size()  || d == 0)
        return 0;

    // Case 2
    else if(B < dgt.size()) {
        // contain 0
        if(A[0] == 0 && B != 1)
            return (d - 1) * pow(d, B - 1);
        else 
            return pow(d, B);
    }

    //Case 3
    else {
          int dp[B + 1], lower[11];
          for(int i = 0; i <= B; i++)
              dp[i] = 0;
          for(int i = 0; i <= 10; i++)
              lower[i] = 0;
          for(int i = 0; i < d; i++)
              lower[A[i] + 1] = 1;

          for(int i = 1; i <= 10; i++)
              lower[i] = lower[i-1] + lower[i]; 

          bool flag = true;
          dp[0] = 0;
          for(int i = 1; i <= B; i++) {
              d2 = lower[dgt[i-1]];
              dp[i] = dp[i-1] * d;

              // For first index we can't use 0
             if(i == 1 &&  A[0] == 0 && B != 1)
                 d2 = d2 - 1;

             //Whether (i-1) dgt of generated number can be equal to (i - 1) dgt of C.
             if(flag)
                 dp[i] += d2;
             //Is dgt[i - 1] present in A ?
                flag = flag & (lower[dgt[i-1] + 1] == lower[dgt[i-1]] + 1);
        }
    return dp[B];                   
    } 
}
