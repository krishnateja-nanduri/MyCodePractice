#include <iostream>
using namespace std;
void sort(int arr[],int b,int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(arr[i]==b)
            break;
    }
    for(;i<n;i++)
    {
        arr[i]=arr[i+1];
    }
    arr[n]=-1;
}

int main() {
    int no;
    cin>>no;
    int total,n,a,b;
    while(no>0)
    {
        no--;
        cin>>total>>n;
        int unread[total]={-1},read[total]={-1},trash[total]={-1};
        for(int i=0;i<total;i++)
        {
            unread[i]=i+1;
        }
        int i=-1,j=-1,k=(total-1);
        while(n>0)
        {
            n--;
            cin>>a>>b;
            switch(a)
            {
            case 1:
                read[++i]=b;
                sort(unread,b,k);
                k--;
                break;
            case 2:
                trash[++j]=b;
                sort(read,b,i);
                i--;
                break;
            case 3:
                trash[++j]=b;
                sort(unread,b,k);
                k--;
                break;
            case 4:
                read[++i]=b;
                sort(trash,b,j);
                j--;
                break;
            }
            
        }
        if(unread[0]==-1)
            cout<<"EMPTY";
        else
            for(int c=0;c<=k;c++)
                cout<<unread[c]<<" ";
        cout<<endl;
        //cout<<i;
        if(read[0]==-1)
            cout<<"EMPTY";
        else
            for(int c=0;c<=i;c++)
                cout<<read[c]<<" ";
        cout<<endl;
        if(trash[0]==-1)
            cout<<"EMPTY";
        else
            for(int c=0;c<=j;c++)
                cout<<trash[c]<<" ";
        cout<<endl;
    }
	return 0;
}
