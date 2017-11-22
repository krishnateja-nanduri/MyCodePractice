//https://www.interviewbit.com/problems/substring-concatenation/

vector<int> Solution::findSubstring(string S, const vector<string> &L) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        vector<int> out;
        if (L.size()==0) return out;
         
        unordered_map<string,int> wordmap;
        for (int i=0;i<L.size();i++) {
            wordmap[L[i]]++;
        }
         
        int wordsize = L[0].size();
         
        if (S.size()<wordsize*L.size())
            return out;
             
        for (int i=0;i<=S.size()-wordsize*L.size();i++) {
            unordered_map<string,int> wordfound;
            int j=0;
            for (;j<L.size();j++) {
                string temp = S.substr(i+j*wordsize,wordsize);
                if (wordmap.find(temp) == wordmap.end()) {
                    break;
                }
                 
                wordfound[temp]++;
                if (wordfound[temp]>wordmap[temp]) {
                    break;
                }
            }
             
            if (j==L.size()) {
                out.push_back(i);
            }
        }
         
        return out;
    }
