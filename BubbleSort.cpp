#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Bubble Sort
    for(int i=0;i<n-1;i++)//For the number of the passes
    {
        bool flag=true;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=false;
            }
        }
        if(flag)
            break;
    }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

}
