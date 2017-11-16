// https://www.interviewbit.com/problems/window-string/

struct info{
    int frq, arrv;
};

string Solution::minWindow(string S, string T) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    unordered_map <char, info> StringMap;
   
    for(int i = 0; i < T.length(); i++){
        if(StringMap.find(T[i]) == StringMap.end()){
            StringMap[T[i]].frq = 1;
            StringMap[T[i]].arrv = 0;
        }
        else{
            StringMap[T[i]].frq++;
        }
    }
   
    int p = 0, q = 0, len = 0;
    int n = T.size(), N = S.size();
    int minI = 0, maxI = 0, minLen = INT_MAX;
   
    while(1){
       if(len < n){
            if(q == N){
                break;
            }
            if(StringMap.find(S[q]) != StringMap.end()){
                StringMap[S[q]].arrv++;
                if(StringMap[S[q]].arrv <= StringMap[S[q]].frq){
                    len++;
                }
            }
            q++;
       }
       else if(len == n){
            if(q - p < minLen){
                minLen = q - p;
                minI = p;
                maxI = q;
            }
            if(StringMap.find(S[p]) != StringMap.end()){
                StringMap[S[p]].arrv--;
                if(StringMap[S[p]].frq > StringMap[S[p]].arrv){
                    len--;
                }
            }
            p++;
       }
    }
   
    string ans = "";
    
    for(int i = minI; i < maxI; i++){
        ans = ans + S[i];
    }
    
    return ans;
}
