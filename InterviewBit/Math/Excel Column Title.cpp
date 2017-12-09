// https://www.interviewbit.com/problems/excel-column-title/

string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int diff, i = 0, j = 0, length = 0, sum = 0, flag = 0;
    string soln;
    
    while(sum < A){
        length++;
        i++;
        sum = sum + pow(26,i);
    }
    
    sum = sum - pow(26,i);
    diff = A - sum;
    
    while(j != length){
        flag = 0;
        i = 1;
        while(flag == 0){
            int value = i*pow(26, length-j-1);
            if(value < diff){
                i++;
            }
            else{
                diff = diff - (i-1)*pow(26, length-j-1);
                char c = i+64;
                soln = soln + c;
                flag = 1;
            }
        }
        j++;
    }
    
    return soln;
}
