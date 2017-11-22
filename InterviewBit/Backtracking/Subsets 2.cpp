// https://www.interviewbit.com/problems/subsets-ii/

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    vector <vector<int> > sol;
    sort(A.begin(), A.end());
    
    for(long long int i=0; i<pow(2,A.size()); i++){
        vector<int> tmp;
        long long int val = i;
        long long int k = 0;
        
        while(val>0){
            if (val&1)
                tmp.push_back(A[k]);
            
            k++;
            val = val>>1;
        }
        
        sol.push_back(tmp);
    }
    
   sort(sol.begin(), sol.end());
   
   vector <vector<int> > sol2;
   
   for(int i=0;i<sol.size();i++){
        sol2.push_back(sol[i]);
        int j;
        
        for( j=i+1;j<sol.size() && sol[j]==sol[i] ;){
           j++;
        }
        
        i = j-1;
       
   }
    return sol2;
}
