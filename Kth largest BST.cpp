#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;
int k;
void printkthlargest(int*a, int n)
{
	priority_queue<int>pq;
	stack<int>s;
	for (int i = 0; i < n; i++)
	{
		pq.push(a[i]);
		int c = 0;
		bool t = 0;
		if (i >= k - 1)
		{
			while (!pq.empty())
			{
				c++;
				s.push(pq.top());
				pq.pop();
				if (c == k)
				{
					t = 1;
					cout << s.top() << ' ';
					while (!s.empty())
					{
						pq.push(s.top());
						s.pop();
					}
					break;
				}
			}
		}
		if (!t)
			cout << -1 << ' ';
	}
}

int main()
{
	int T; cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		int n; cin >> n;
		int*a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		printkthlargest(a, n);
		cout << endl;
	}
}
