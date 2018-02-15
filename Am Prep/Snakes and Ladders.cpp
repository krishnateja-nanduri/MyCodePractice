//https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem/0

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> ladders;
    map<int,int> snakes;
    int t=0; cin >> t;
    while(t>0){
        t--;
        ladders.clear();
        snakes.clear();
        
        // play ground
        vector<int> arr;
        arr.push_back(0);
        for(int i=1;i<30;i++){
            arr.push_back(INT_MAX);
        }
        //arr[0]=0;
    
        // get ladders and snakes
        int vv=0; cin >> vv;
        int a=0; int b=0;
        for(int i=0;i<vv;i++){
            cin >> a >> b;
            a=a-1; b=b-1;
            if(a<b){
                // it is a ladder
                ladders[a]=b;
            }
            else{
                // it is a snake
                snakes[a]=b;
            }
        }
    
        for(int i=0;i<30;i++){
            if(ladders.find(i) != ladders.end()){
                // there is a ladder from me to another square.
                int ladderend = ladders[i];
                // the distance from me through the ladder to the other end is the same
                arr[ladderend] = min(arr[i],arr[ladderend]);
                continue;   // I continue b/c i have no option but to go up the ladder
            }
            else if(snakes.find(i) != snakes.end()){
                // there is a snake from me to another square.
                int snakeend = snakes[i];
                // the distance from me through the ladder to the other end is the same
                arr[snakeend] = min(arr[i],arr[snakeend]);
                continue;   // I continue b/c i have no option but to go down the snake
            }
    
            for(int j=i+1;j<=i+6 && j<30; j++){
                // adjacents
                arr[j] = min(arr[j],arr[i] + 1);
            }
        }
        
        cout << arr[29] << endl;
    }
	return 0;
}
