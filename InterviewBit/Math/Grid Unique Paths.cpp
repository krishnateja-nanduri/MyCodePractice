// https://www.interviewbit.com/problems/grid-unique-paths/

int Solution::uniquePaths(int A, int B) {
    int soln = 1;
    int x = min (B, A); // if we dont use the min value, soln may overflow.
    
    for(int i=1;i<x;i++){
        soln = (soln *( A+B-2 - i +1))/i;
    }
    return soln;
}
