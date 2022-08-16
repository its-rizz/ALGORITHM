#include<bits/stdc++.h>
using namespace std;

int merge(vector <int> &arr,int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int left[mid-low+1];
    int right[n2];

    int inversion=0;

    int temp=0;
    for(int i=low;i<=mid;i++,temp++)
        left[temp]=arr[i];

    temp=0;
    for(int i=mid+1;i<=high;i++,temp++)
        right[temp]=arr[i];
    
    int first=0,second=0,current=0;
    while(first<n1 and second<n2)
    {
        if(left[first]<=right[second])
        {    arr[low+current]=left[first++]; current++;}

        else
        {    arr[low+current]=right[second++]; inversion+=n1-first;current++;}
    }

    while(first<n1)
    {    arr[low+current]=left[first++]; current++;}

    while(second<n2)
    {    arr[low+current]=right[second++]; current++;}


    return inversion;

}

int mergeSort(vector <int> &arr,int low,int high)
{
    if(low>=high)
        return 0;

    else
    {
        int mid=(low+high)/2;
        int c1=mergeSort(arr,low,mid);
        int c2=mergeSort(arr,mid+1,high);
        int c=merge(arr,low,mid,high);
        return c+c1+c2;
    }
}





int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<mergeSort(arr,0,n-1)<<endl;;
    for(auto &it:arr)
        cout<<it<<" ";
    cout<<endl;
}
