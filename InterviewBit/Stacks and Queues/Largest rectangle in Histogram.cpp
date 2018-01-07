//https://www.interviewbit.com/problems/largest-rectangle-in-histogram/

int Solution::largestRectangleArea(vector<int> &height) {
     if (height.empty()){return 0;}
        vector<int>l(height.size(),0);    
        vector<int>r(height.size(),0);
         
        for (int i = 0; i<height.size();i++){   
            int j=i;
            while((j>0) && (height[i]<=height[j-1])){ j=l[j-1];}
            l[i]=j;
        }
         
        for (int i = height.size()-1;i>=0;i--){   
            int j=i;
            while( (j<height.size()-1) && (height[i]<=height[j+1])){ j=r[j+1];}
            r[i]=j;
        }
             
        int maxa=0;
        for (int i=0;i<l.size();i++){
            maxa = max(maxa,((r[i]-l[i]+1)*height[i]));
        }
        return maxa;
}

