// https://www.interviewbit.com/problems/max-distance/

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<bool> tempArr(A.size());
    int min = A[0];
    int max_distance = 0;
    int i = A.size()-1;
    int j = A.size()-1;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] > min){
            tempArr[i] = false;
        }
        else{
            min = A[i];
            tempArr[i] = true;
        }
    }

    LOOP:while(i >= 0){
        if(tempArr[i] == false){
            i--;
            goto LOOP;
        }
        while((A[i] > A[j]) && (j > i)){
            j--;
        }
        if((j-i) > max_distance){
            max_distance = j-i;
        }
        i--;
    }
    return max_distance;
}
