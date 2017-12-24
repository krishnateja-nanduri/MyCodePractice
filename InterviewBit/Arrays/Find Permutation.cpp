//https://www.interviewbit.com/problems/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
        vector<int> ans;
       
        int d=0,i;
       
        for(auto x:A) {
            if(x=='D') d++;
        }
       
        i=d+1;
       
        ans.push_back(i++);
       
        for(auto x:A){
            if(x=='I') {
                ans.push_back(i++);
            }else {
                ans.push_back(d--);
            }
        }
       
        return ans;
}
