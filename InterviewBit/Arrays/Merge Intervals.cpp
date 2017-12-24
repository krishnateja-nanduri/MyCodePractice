//https://www.interviewbit.com/problems/merge-intervals/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool myfunc(Interval a, Interval b) {
        return( a.start<b.start);
    }
    vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

        vector<Interval> res;
        vector<Interval>::iterator it;  
        for (it = intervals.begin();it!=intervals.end();it++){
            if (newInterval.start<(*it).start){
                intervals.insert(it,newInterval);
                break;
            }
        }    
        if (it==intervals.end()){intervals.insert(it,newInterval);}
         
         
        if (intervals.empty()) {return res;}
           
        res.push_back(*intervals.begin());
        for (it = intervals.begin()+1;it!=intervals.end();it++){
            if ((*it).start>res.back().end){res.push_back(*it);}
            else{ res.back().end = max(res.back().end,(*it).end);}
        }
        return res;
    }

