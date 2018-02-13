//Given an array of numbers, find pairs that have sum k

#include <iostream>
#include <algorithm>
 
using namespace std;
 
void findpairsum(int arr[], int len, int sum)
{
    std::sort(arr, arr+len);
    int i = 0;
    int j = len -1;
    while( i < j){
        while((arr[i] + arr[j]) <= sum && i < j)
        {
            if((arr[i] + arr[j]) == sum)
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            i++;
        }
        j--;
        while((arr[i] + arr[j]) >= sum && i < j)
        {
            if((arr[i] + arr[j]) == sum)
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            j--;
        }
    }
}

 
int main(void)
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    findpairsum(arr, len, 7);
}
 

