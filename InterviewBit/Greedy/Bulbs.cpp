// https://www.interviewbit.com/problems/bulbs/

int Solution::bulbs(vector<int> &A) {
   int state=0, soln=0;
   
   for(int i =0; i<A.size(); i++){
       if(A[i]==state){
           soln++;
           state = 1- state;
       }
   }
   
   return soln;
}

