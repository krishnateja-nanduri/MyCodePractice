//https://www.interviewbit.com/problems/unique-binary-search-trees-ii/

int Solution::numTrees(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> count(n+1, 0);  
            count[0] =1;  
            count[1] =1;  
            for(int i =2; i<=n; i++)  
            {  
                 for(int j =0; j<i; j++)  
                {  
                      count[i] += count[j]*count[i-j-1];   
                 }  
            }  
    return count[n];  
}

