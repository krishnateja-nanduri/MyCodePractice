//https://www.interviewbit.com/problems/seats/

long long save(long long val) {
    val %= 10000003;
    while (val < 0)
        val += 10000003;
    return val; 
}

int Solution::seats(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> seatPos;
    int rightStart = 0;
    long long sumL = 0, sumR = 0;
    long long addNL = 0, addNR = 0;
    for (int it = 0; it < A.length(); ++it) {
        if (A[it] == 'x') {
            addNR = save(addNR+seatPos.size());
            seatPos.push_back(save(it));
            sumR = save(sumR+it);
        }
    }
    long long ans = LLONG_MAX;
    for (int it = 0; it < A.length(); ++it) {
    	while ((rightStart != seatPos.size()) and (seatPos[rightStart] < it)) {
    		sumL = save(sumL+seatPos[rightStart]);
    		sumR = save(sumR-seatPos[rightStart]);
    		addNL = save(addNL+rightStart);
    		++rightStart;
    		addNR = save(addNR-save(seatPos.size()-rightStart)); 
    	}
        long long leftHop = save(save((it-1)*rightStart)-save(addNL+sumL));
        long long rightHop = save(save(sumR-addNR)-save(it*save(seatPos.size()-rightStart)));
        ans = min(ans, save(leftHop+rightHop));
    }
    return (ans == LLONG_MAX ? 0 : ans);
}

