// https://www.interviewbit.com/problems/max_imum-consecutive-gap/

int Solution::max_imumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A.size() < 2){
        return 0;
    }
    
    vector<int> Min_f(A.size(), -1);
    vector<int> Max_f(A.size(), -1);
    
    int max_dist = 0, min_i = INT_MAX, max_i = INT_MIN;
    int gap = 0, bucket = 0, ind = 0;
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] < min_i){
            min_i = A[i];
        }
        if(A[i] > max_i){
            max_i = A[i];
        }
    }
    
    gap = max_i - min_i;
    gap = gap/(A.size()-1);
    
    if(gap == 0){
        return max_i - min_i;
    }
    
    for(int i = 0; i < A.size(); i++){
        bucket = (int)((A[i] - min_i)/gap);
        if(Min_f[bucket] < 0){
            Min_f[bucket] = A[i];
            Max_f[bucket] = A[i];
        }
        else{
            Min_f[bucket] = min(A[i], Min_f[bucket]);
            Max_f[bucket] = max(A[i], Max_f[bucket]);
        }
    }
    
    int max_diff = 0;
    
    for(int i = 0; i < Min_f.size(); i++){
        if(Min_f[i] >= 0){
            max_diff = max(max_diff, Min_f[i]-Max_f[ind]);
            ind = i;
        }    
    }
    
    return max_diff;
    
}
