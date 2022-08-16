#include<bits/stdc++.h>
using namespace std;


int partition(vector <int> &arr,int low,int high)//Here the first element is taken as the pivot 
{
    int pivot=arr[low];
    int i=low;
    for(int j=low+1;j<=high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i],arr[low]);
    return i;
}


void quickSort(vector<int> &arr,int low,int high)
{
    if(low>=high)
        return;
    
    else
    {
        int p=partition(arr,low,high);
        quickSort(arr,low,p);
        quickSort(arr,p+1,high);
    }
}



int main()
{
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];

    quickSort(arr,0,n-1);
    for(auto &it:arr)
        cout<<it<<" ";
    cout<<endl;
}
