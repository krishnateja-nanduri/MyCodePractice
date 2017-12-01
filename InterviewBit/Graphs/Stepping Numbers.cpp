// https://www.interviewbit.com/problems/stepping-numbers/

void Steps(int A, int B, vector<int>& soln, long long int num){
    if(num > B){
        return;
    }
    
    int last = num%10;
    
    if(num >= A){
        soln.push_back(num);
    }
    
    if(last == 0){
        Steps(A, B, soln, num*10 + 1);
    }
    else if(last == 9){
        Steps(A, B, soln, num*10 + 8);
    }
    else{
        Steps(A, B, soln, num*10 + last - 1);
        Steps(A, B, soln, num*10 + last + 1);
    }
}

vector<int> Solution::stepnum(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> soln;
    vector<int> a;
    vector<int> b;
    
    if(A > B){
        return soln;
    }
    
    if(A == 0){
        soln.push_back(0);
    }
    
    for(int i = 1; i < 10; i++){
        Steps(A, B, soln, (long long int)i);
    }
    
    if(soln.size() != 0){
        sort(soln.begin(), soln.end());
    }
    
    return soln;
}
