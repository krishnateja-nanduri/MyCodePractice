//https://www.interviewbit.com/problems/median-of-array/

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int l,r,mid;
   int n=A.size();
   int m=B.size();
   if(n==0){
        if(m&1)
            return (double)B[m/2];
        return (double)(B[m/2-1]+B[m/2])/2; 
   }
   if(m==0){
       if(n&1)
            return (double)A[n/2];
        return (double)(A[n/2-1]+A[n/2])/2; 
   }
   int med_Index;
   int med=-1;
   int med_Value;
   bool first=1;
    l=0; r=n-1;
    while(l<=r){
        mid=(l+r)>>1;
        med_Index=(n+m)/2-mid;
        if(med_Index>=0 && med_Index<m){
           if(A[mid]<=B[med_Index]){
               if(med_Index==0 || (med_Index>0 && B[med_Index-1]<=A[mid])){
                    med=mid;
                    med_Value=A[mid];
                    l=n;
               }
               else l=mid+1;
           }else r=mid-1;
        }
        else if(med_Index==m){
            if(A[mid]>=B[med_Index-1]){
                med=mid;
                med_Value=A[mid];
                l=n;
            }else l=mid+1;
        }
        else if(med_Index<0) r=mid-1;
        else l=mid+1;
    }
    if(med < 0){
        first=0;
        l=0;r=m-1;
        while(l<=r){
            mid=(l+r)>>1;
            med_Index=(n+m)/2-mid;
            if(med_Index>=0 && med_Index<n){
               if(B[mid]<=A[med_Index]){
                   if(med_Index==0 || (med_Index>0 && A[med_Index-1]<=B[mid])){
                        med=mid;
                        med_Value=B[mid];
                        l=m;
                   }
                   else l=mid+1;
               }else r=mid-1;
            }
            else if(med_Index==n){
                if(B[mid]>=A[med_Index-1]){
                    med=mid;
                    med_Value=B[mid];
                    l=m;
                }else l=mid+1;
        }
            else if(med_Index<0) r=mid-1;
            else l=mid+1;
        }
    }
    if((m+n)&1)
        return (double)med_Value;
    int value1,value2;
    if(first){
        if(med==0)
            value1=INT_MIN;
        else value1=A[med-1];
         if(B[0]>med_Value)
            return (double)(med_Value+value1)/2;
        l=0;r=m-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(B[mid]==med_Value){
                r=mid;
                l=m;
            }else if(B[mid]<med_Value)
                l=mid+1;
            else r=mid-1;
        }
        value2=B[r];
    }else{
        if(med==0)
            value1=INT_MIN;
        else value1=B[med-1];
        if(A[0]>med_Value)
            return (double)(med_Value+value1)/2;
        l=0;r=n-1;
        while(l<=r){
            mid=(l+r)>>1;
            if(A[mid]==med_Value){
                r=mid;
                l=n;
            }else if(A[mid]<med_Value)
                l=mid+1;
            else r=mid-1;
        }
        value2=A[r];
    }
    return (double)(med_Value+max(value1,value2))/2;
    
}
