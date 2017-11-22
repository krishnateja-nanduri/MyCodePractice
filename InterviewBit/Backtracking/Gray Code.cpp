

vector<int> Solution::grayCode(int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        if(n == 0) {
            vector<int> sol;
            sol.push_back(0);
            return sol;
        } else {
            vector<int> previous = grayCode(n - 1);
            vector<int> sol(previous);
            for(int i = previous.size() - 1; i >= 0; --i) {
                sol.push_back((int)pow(2.0, n - 1) + previous[i]);
            }
            return sol;
        }
    }
