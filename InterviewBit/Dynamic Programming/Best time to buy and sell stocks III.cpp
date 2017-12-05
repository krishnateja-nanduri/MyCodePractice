//https://www.interviewbit.com/problems/best-time-to-buy-and-sell-stocks-iii/

int Solution::maxProfit(const vector<int> &prices) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

        int mprof = 0;
        if (prices.size()>1){
            int maxprof = 0;
            vector<int> mp; // max profit before each element
            mp.push_back(0);
            int st = *prices.begin();
            for(int i = 1 ; i<=prices.size();i++){  //compute mp vector
                if (mprof < prices[i]-st){mprof = prices[i]-st;}
                if (prices[i]<st){st = prices[i];}
                mp.push_back(mprof);
            }
            mprof = 0;
            int ed = *(prices.end()-1);
            for (int i = prices.size()-2; i>=0; i--){
                if (mprof < ed - prices[i] + mp[i]) { mprof = ed - prices[i] + mp[i];}
                if (prices[i]>ed) {ed = prices[i];}
            }
        }
        return mprof;
    }
