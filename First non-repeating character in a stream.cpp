#include<iostream>
#include<queue>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n;char s;
	while(t > 0)
	{
		cin>>n;
		queue<char> q;
		int cnt[256]={0};
		for(int i=0;i<n;i++)
		{
			cin>>s;
			cnt[s]++;
			if(cnt[s] == 1)
			{
				q.push(s);
				if(q.front()==s)
					cout<<s<<" ";
				else
					cout<<q.front()<<" ";
			}
			else
			{
				while(cnt[q.front()] !=1 && !q.empty())
					q.pop();
				if(q.empty())
					cout<<"-1 ";
				else
					cout<<q.front()<<" ";
			}
		}
		cout<<endl;
		t--;
	}
}
