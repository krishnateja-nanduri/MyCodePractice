//https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

      int i=0, j= A.size()-1;
      while(i<j)
      {
        while(!isalnum(A[i])&&i<j)
        {
            i++;
        }
        while(!isalnum(A[j])&&i<j)
        {
            j--;
        }
        if(tolower(A[i]) != tolower(A[j]) ){
            return 0;
        }
        i++;
        j--;
          
      }
      return 1;
}

