// https://www.interviewbit.com/problems/edit-distance/

int Solution::minDistance(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int row = A.size();
    int col = B.size();
    
    vector<vector<int> > tmp(row+1, vector<int>(col+1));
    
    for(int i = 0; i < tmp.size(); i++){
        for(int j = 0; j < tmp[0].size(); j++){
           if(i == 0){
                tmp[i][j] = j;
            } 
            else if(j == 0){
                tmp[i][j] = i;
            }
            else if(A[i-1] == B[j-1]){
                tmp[i][j] = tmp[i-1][j-1];
            }
            else{
                tmp[i][j] = min(tmp[i-1][j-1], tmp[i-1][j]);
                tmp[i][j] = min(tmp[i][j-1], tmp[i][j]);
                tmp[i][j] = tmp[i][j]+1;
            }
        }
    }
    
    return tmp[row][col];
}
