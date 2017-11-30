// https://www.interviewbit.com/problems/black-shapes/

void BFSearch (int i, int j, vector<string> &A){
    if(i>0 && A[i-1][j]=='X'){
        A[i-1][j]='O';
        BFSearch(i-1, j, A);
    }
    
    if(i<A.size()-1 && A[i+1][j]=='X'){
        A[i+1][j]='O';
        BFSearch(i+1, j, A);
    }
    
    if(j>0 && A[i][j-1]=='X'){
        A[i][j-1]='O';
        BFSearch(i, j-1, A);
    }
    
    if(j<A[0].size()-1 && A[i][j+1]=='X'){
        A[i][j+1]='O';
        BFSearch(i, j+1, A);
    }
    
}


int Solution::black(vector<string> &A) {
    int length = A.size();
    int length_vector = A[0].size();
    int soln = 0;
    
    for(int i=0; i<length; i++){
        for(int j=0; j<length_vector; j++){
            if(A[i][j]=='X'){
                A[i][j]='O';
                BFSearch(i,j,A);
                soln++;
            }
         
        }
        
    }
    
    return soln;
    
}
