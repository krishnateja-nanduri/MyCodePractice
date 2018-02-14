//https://practice.geeksforgeeks.org/problems/check-if-string-is-rotated-by-two-places/0

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin >> t;
	while(t--)
	{
	    string a,b;
	    cin >> a >> b;
	    int i = 0, j = 2,  flag = 0, check = 1, n = a.length(), m = b.length();
	    if(n != m)
	    {
	        cout << 0 << endl;
	        continue;
	    }
	    for(; i < n; i++)
	    {
	        if(a[i] != b[j])
	        {
	            check = 0;
	            break;
	        }
	        j = (j+1)%n;
	    }
	    if(check == 1)
	    {
	        cout << 1 << endl;
	        continue;
	    }
	    check = 1, j = m-2;
	    for(; i < n; i++)
	    {
	        if(a[i] != b[j])
	        {
	            check = 0;
	            break;
	        }
	        j = (j+1)%n;
	    }
	     if(check == 1)
	    {
	        cout << 1 << endl;
	        continue;
	    }
	    cout << 0 << endl;
	}
	return 0;
}
