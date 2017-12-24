//https://www.interviewbit.com/problems/min-steps-in-infinite-grid/

// Input : X and Y co-ordinates of the points in order. 
// Each point is represented by (X[i], Y[i])
int Solution::coverPoints(vector<int> &X, vector<int> &Y) 
{
    int s1=X.size(), s2=Y.size(),ans=0;
    for(int i=1;i<s1;i++)
    {
        ans = ans + (abs(X[i]-X[i-1])<abs(Y[i]-Y[i-1])?abs(Y[i]-Y[i-1]):abs(X[i]-X[i-1]));
    }
    return ans;
} 

