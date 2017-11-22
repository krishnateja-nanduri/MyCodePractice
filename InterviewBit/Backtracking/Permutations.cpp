//https://www.interviewbit.com/problems/permutations/

void perm(vector<int> num,int k,int n, vector<vector<int> > &res){
        if (k==n){
            res.push_back(num);
        }else{
            for (int i=k;i<=n;i++){
                int tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
                 
                perm(num,k+1,n,res);
                 
                tmp = num[k];
                num[k]=num[i];
                num[i]=tmp;
            }
        }
    }

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<vector<int> > res;
        perm(A,0,(A.size()-1),res);
        return res;
}

