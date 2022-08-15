#include<bits/stdc++.h>
using namespace std;

void merge(vector <int> &arr,int low,int mid,int high)
{
    int left[mid-low+1];
    int right[high-mid];

    int temp=0;
    for(int i=low;i<=mid;i++,temp++)
        left[temp]=arr[i];

    temp=0;
    for(int i=mid+1;i<=high;i++,temp++)
        right[temp]=arr[i];
    
    int first=0,second=0,current=0;
    while(first<mid-low+1 and second<high-mid)
    {
        if(left[first]<right[second])
        {    arr[low+current]=left[first++]; current++;}

        else
        {    arr[low+current]=right[second++]; current++;}
    }

    while(first<mid-low+1)
    {    arr[low+current]=left[first++]; current++;}

    while(second<high-mid)
    {    arr[low+current]=right[second++]; current++;}


}

void mergeSort(vector <int> &arr,int low,int high)
{
    if(low>=high)
        return;

    else
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}





int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    mergeSort(arr,0,n-1);
    for(auto &it:arr)
        cout<<it<<" ";
    cout<<endl;
}
