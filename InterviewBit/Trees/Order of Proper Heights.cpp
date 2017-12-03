//https://www.interviewbit.com/problems/order-of-people-heights/

vector<int> order(vector<int> &heights, vector<int> &infronts) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

 vector<int> result(heights.size(),-1);
 map<int,int> htsAndFronts;
 for(int i = 0;i<heights.size();i++)
 {
    htsAndFronts[heights[i]] = infronts[i];
 }
 for (map<int,int>::iterator it = htsAndFronts.begin(); it != htsAndFronts.end(); ++it)
 {
    int i = 0;
    int j = 0;
    while(i!=it->second)
    {
         if(result[j]==-1)
              i++;
          j++;
    }
     while(result[j]!=-1)
           j++;
      result[j] = it->first;
 }

  return result;
}
