// https://www.interviewbit.com/problems/points-on-the-straight-line/

int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0 || B.size() == 0){
        return 0;
    }
    
    unordered_map<double, int> PointMap;
    int sol = 1;
    for(int i = 0; i < A.size(); i++){
        int dupli = 1;
        int verti = 0;
        for(int j = i+1; j < A.size(); j++){
            if(A[i] == A[j]){
                if(B[i] == B[j]){
                    dupli++;
                }
                else{
                    verti++;
                }
            }
            else{
                double slope = 0.0;
                double x = A[j] - A[i];
                double y = B[j] - B[i];
                if(B[j] != B[i]){
                    slope = (1.0 * (y/x));
                }
                if(PointMap.find(slope) != PointMap.end()){
                    PointMap[slope]++;
                }
                else{
                    PointMap[slope] = 1;
                }
            }
        }
        auto it = PointMap.begin();
        while(it != PointMap.end()){
            int t = it->second;
            if((t + dupli) > sol){
                sol = t + dupli;
            }
            it++;
        }
        if((verti + dupli) > sol){
            sol = verti + dupli;
        }
        PointMap.clear();
    }
    
    return sol;
}
