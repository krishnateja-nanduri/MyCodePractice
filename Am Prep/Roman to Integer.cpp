//https://practice.geeksforgeeks.org/problems/roman-number-to-integer/0

#include<bits/stdc++.h>

using namespace std;

int roman_to_int(char c)
{
    switch(c){
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int main()
{
    int t;
    
    for(cin >>t;t--;){
        
        char s[25];
        
        cin >> s;
        
        int n = strlen(s)-1;
        int ans = 0;
        int recent = -1;
        for(int i=n;i>=0;i--){
            int x = roman_to_int(s[i]);
            if(recent>x)   ans -= x;
            else {
                ans += x;
                recent = x;
            }
        }
        
        cout << ans <<endl;
    }
    
    return 0;
}

