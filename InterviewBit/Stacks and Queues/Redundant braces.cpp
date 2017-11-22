//https://www.interviewbit.com/problems/redundant-braces/

int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    stack <char> s;

    for(int i=0; i<A.length(); i++){
        while(i<A.length() && ( A[i]=='(' || A[i]=='+' || A[i]=='*' || A[i]=='-' || A[i]=='/') ){
            s.push(A[i]);
            i++;
        }
        
        if(A[i]==')'){
            if(!s.empty() && (s.top()=='(') )
                return 1;
            
            else{
                while(s.top()!='(')
                    s.pop();
                s.pop();
            }
        }
    }
    
    return 0;
}
