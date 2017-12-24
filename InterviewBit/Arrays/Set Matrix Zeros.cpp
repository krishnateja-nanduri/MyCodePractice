//https://www.interviewbit.com/problems/set-matrix-zeros/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

 int r = A.size();
 int c = A[0].size();
 bool firstRowHasZero = false, firstColHasZero = false;

for(int j=0;j<c;j++){
     if(A[0][j]==0 ){
         firstRowHasZero=true;
         break;
     }
 }
 
 for(int j=0;j<r;j++){
     if(A[j][0]==0){
         firstColHasZero=true;
         break;
         
     }
 }
 
 for(int i =1;i<r;i++){
     for (int j=1;j<c;j++){
        if(A[i][j]==0){
            A[i][0]=0;
            A[0][j]=0;
        }
     }
 }
 
 
 for(int i=1;i<r;i++){
     for(int j=1;j<c;j++){
         if(A[i][0]==0 || A[0][j]==0){
             A[i][j]=0;
         }
     }
 }
 
 if(firstRowHasZero){
     for(int i=0;i<c;i++){
         A[0][i]=0;
     }
 }
 
 if(firstColHasZero){
     for(int i=0;i<r;i++){
         A[i][0]=0;
     }
}
}

