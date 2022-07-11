#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n; cin>>n;
    int arr[n];

    for(int i=0;i<n;i++)
        cin>>arr[i];

    //Insertion Sort
    for(int i=0;i<n-1;i++)//The number of passes
    {
        int j=i+1;
        int x=arr[j];
        //Calculate the number till the element is greater than the current element
        while(j>=0 and arr[j]>x)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j]=x;
    }
    

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;

}
