// https://www.interviewbit.com/problems/shortest-unique-prefix/

struct TrNode{
    TrNode* child[26];
    bool unique;
    
    TrNode(){
        for(int i = 0; i < 26; i++){
            child[i] = NULL;
        }
        unique = true;
    }
};

void buildTr(TrNode* root, string s){
    TrNode* curr = root;
    
    int i = 0;
    int a = s[i] - 97;
    while(i < s.size()){
        if(curr->child[a] == NULL){
            TrNode* node = new TrNode();
            curr->child[a] = node;
        }
        else{
            (curr->child[a])->unique = false;
        }
        curr = curr->child[a];
        i++;
        if(i != s.size()){
            a = s[i] - 97;
        }
    }
}

string getPre(TrNode* root, string s){
    string sol = "";
    
    TrNode* curr = root;
    
    if(s.size() == 0){
        return sol;
    }
    
    int i = 0;
    
    do{
        curr = curr->child[s[i]-97];    
        sol = sol + s[i];
        i++;   
    }while(i < s.size() && curr->unique == false);
    
    return sol;
}

vector<string> Solution::prefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> sol;
    
    TrNode* root = new TrNode();
    
    for(int i = 0; i < A.size(); i++){
        buildTr(root, A[i]);
    }
    
    for(int i = 0; i < A.size(); i++){
        sol.push_back(getPre(root, A[i]));
    }
    
    return sol;
    
}
