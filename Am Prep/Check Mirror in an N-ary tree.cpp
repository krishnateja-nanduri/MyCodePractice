//https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/0

#include<iostream>
#include<cstring>
#include<map>
#include<vector>
using namespace std;

int maxNum;
map<int,vector<int> > createTree(int edge)
{
	map<int,vector<int> >m;
	while(edge--)
	{   
		int parent,child;
		cin>>parent>>child;
		if(parent>maxNum)
			maxNum=parent;
		m[parent].push_back(child);
	}
return m;
   
}
bool Isrev(vector<int>fir,vector<int>sec)
{
	for(int i=0;i<fir.size();i++)
	{
		if(fir[i]!=sec[sec.size()-1-i])
			return false;
	}
	return true;
}
bool checkMirror(map<int,vector<int> >fir,map<int,vector<int> >sec)
{
   int i=0;
   while(i<=maxNum)
   {
   	if(fir[i].size()!=0)
   	{
   		if(fir[i].size()!=sec[i].size())
   			return false;
   		bool check=Isrev(fir[i],sec[i]);
   		if(!check)
   			return false;
   	}
   	i++;

   }
   return true;

     
}
int main()
{
	int test;
	cin>>test;
	while(test--)
	{   maxNum=-1;
		map<int,vector<int> >fir,sec;
		int node,edge;
		cin>>node>>edge;
		fir=createTree(edge);
		sec=createTree(edge);
		cout<<checkMirror(fir,sec)<<endl;
	}

}
