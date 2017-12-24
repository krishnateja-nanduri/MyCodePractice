//https://www.interviewbit.com/problems/flip/

vector<int> Solution::flip(string A) {
    vector<int> ZeroOne(A.size()); // if zero then 1, if one then -1.
    vector<int> ans;
    
    for(int i = 0; i<A.size(); i++){
        if(A[i]=='0')
            ZeroOne[i] = 1;
        
        else
            ZeroOne[i] = -1;
    }
    
    int full=0, left=0, right=0, maxSum=INT_MIN;
    int l_soln=0, r_soln=0;
    
    for(int i=0; i<A.size(); i++){
        full+=ZeroOne[i];
        
        if(full<0){
            left=i+1;
            full=0;
        }
        
        else if(full>maxSum){
            l_soln = left;
            r_soln = i;
            maxSum=full;
        }
    }
    
    if(maxSum<=0){
        return ans;
    }
    
    else{
        ans.push_back(l_soln+1);
        ans.push_back(r_soln+1);
    }
    
    return ans;
}
