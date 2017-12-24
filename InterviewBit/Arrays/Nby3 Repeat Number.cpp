//https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int len = A.size();
    if (A.size() == 0) {
        return -1;
    }
    if (A.size() == 1) {
        return A[0];
    }
    
    int c1 = A[0];
    int c2 = A[1];
    int count_c1 = 0;
    int count_c2 = 0;
    
    for(int num: A){
        if(c1 == num){
            count_c1++;
        }
        else if(c2 == num){
            count_c2++;
        }
        else if(count_c1 == 0){
            c1 = num;
            count_c1 = 1;
        }
        else if(count_c2 == 0){
            c2 = num;
            count_c2 = 1;
        }
        else{
            count_c1--;
            count_c2--;
        }
    }
    
    count_c1 = 0;
    count_c2 = 0;
    for(int num : A){
        if(c1 == num){
            count_c1++;
        }
        else if(num == c2){
            count_c2++;
        }
    }
    
    if(count_c1 > len/3){
        return c1;
    }
    else if(count_c2 > len/3){
        return c2;
    }
    else{
        return -1;
    }
        
}
