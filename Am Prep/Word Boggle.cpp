//https://practice.geeksforgeeks.org/problems/word-boggle/0

#include<bits/stdc++.h>
using namespace std;

struct node{
    node* next[256];
    bool end;
    node(): next(), end(){}
};

int dr[][2]={{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};

inline bool valid(int i,int j,int m,int n){
    if(i<0 || i>=m || j<0 || j>=n)
        return 0;
    return 1;
}
void insert(node* r, string& s, int i){
    if(s.size()==i){
        r->end=1;
        return;
    }
    if(!r->next[s[i]])
        r->next[s[i]]=new node();
    insert(r->next[s[i]],s,i+1);
}

void dfs(node* r, vector<vector<char> >& a, int i,int j,
        vector<vector<char> >& d, string& ts, set<string>& st){
    d[i][j]=1;
    if(r->end){
        st.insert(ts);
    }
    int m=a.size(),n=a[0].size();
    for(int k=0;k<8;k++){
        int ti=i+dr[k][0],tj=j+dr[k][1];
        if(valid(ti,tj,m,n) && !d[ti][tj] && r->next[a[ti][tj]]){
            ts+=a[ti][tj];
            dfs(r->next[a[ti][tj]],a,ti,tj,d,ts,st);
            ts.pop_back();
        }
    }
    d[i][j]=0;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int m,n;
	    node* root=new node();
	    cin>>n;
	    string s;
	    for(int i=0;i<n;i++){
	        cin>>s;
	        insert(root,s,0);
	    }
	    cin>>m>>n;
	    vector<vector<char> > a(m,vector<char>(n));
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>a[i][j];
	        }
	    }
	    vector<vector<char> > d(m,vector<char>(n,0));
	    set<string> st;
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            string ts="";
	            ts+=a[i][j];
	            if(root->next[a[i][j]])
	                dfs(root->next[a[i][j]],a,i,j,d,ts,st);
	        }
	    }
	    if(st.empty())
	        cout<<-1;
	    else{
    	    for(auto it=st.begin();it!=st.end();it++){
    	        cout<<*it<<" ";
    	    }
	    }
	    cout<<endl;
	}
	return 0;
}
