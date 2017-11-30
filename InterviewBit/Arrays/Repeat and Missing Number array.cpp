//https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int len = A.size();
    long long int sumOfN = (len * (len+1) ) /2, sumOfNsq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber1=0, missingNumber2=0;
    
    for(int i=0;i<A.size(); i++){
       sumOfN -= (long long int)A[i];
       sumOfNsq -= (long long int)A[i]*(long long int)A[i];
    }
    
    missingNumber1 = (sumOfN + sumOfNsq/sumOfN)/2;
    missingNumber2= missingNumber1 - sumOfN;
    vector <int> ans;
    ans.push_back(missingNumber2);
    ans.push_back(missingNumber1);
    return ans;
    
}
