//https://www.interviewbit.com/problems/combinations/

void pair(vector<int> tmp, int curr, int n, int k, vector<vector<int> >& sol){
    if(tmp.size() == k){
        sol.push_back(tmp);
        return;
    }
    else if(curr > n){
        return;
    }
    
    for(int i = curr; i <= n; i++){
        vector<int> t(tmp);
        t.push_back(i);
        pair(t, i+1, n, k, sol);
    }
}

vector<vector<int> > Solution::combine(int n, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > sol;
    
    for(int i = 1; i <= n; i++){
        vector<int> tmp(1, i);
        pair(tmp, i+1, n, k, sol);
    }
    
    return sol;
}
