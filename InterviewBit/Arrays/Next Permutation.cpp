// https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
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
  
