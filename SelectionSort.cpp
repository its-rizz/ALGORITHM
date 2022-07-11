#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Selection Sort
    for(int i=0;i<n-1;i++)
    {
        int num=arr[i];
        int ind=i;
        for(int j=i+1;j<n;j++)//Find the smallest number 
        {
            if(num>arr[j])
            {
                ind=j;
                num=arr[j];
            }
            swap(arr[i],arr[ind]);
        }
    }
    

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

}
