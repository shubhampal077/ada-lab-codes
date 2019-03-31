#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
int partition(int arr[],int low,int high)
{
    int pivot=arr[low];
    int i=low,j=high;
    while(1)
    {
        while(arr[i]<pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i>=j)
            return j;
        swap(arr[i],arr[j]);
    }
}
int partition_m(int arr[],int low,int high)
{
    int mid=(low+high)/2;
    int a,b,c;
    a=arr[low];b=arr[mid];c=arr[high];
    /*if(a>b)
    {
        if(b>c)
            swap(arr[mid],arr[low]);
        else   
            swap(arr[high],arr[low]);

    }
    else if(a<=b)
    {
        if(a<c)
            swap(arr[high],arr[low]);
    }*/
    vector<pair<int,int>> vec;
    vec.push_back({a,low});
    vec.push_back({b,mid});
    vec.push_back({c,high});
    sort(vec.begin(),vec.end());
    int x=vec[1].second;
    swap(arr[low],arr[x]);
    return partition(arr,low,high);
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi= partition_m(arr,low,high);
        quicksort(arr,low,pi);
        quicksort(arr,pi+1,high);
    }
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //int index;
    int arr[]={27,82,31,5,98,23,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    //cout<<"enter the index in which you want to set pivot\n ";
    //cin>>index;
    //swap(arr[0],arr[index]);
    quicksort(arr, 0, n - 1); 
    cout<<"Sorted array: \n"; 
    printArray(arr, n); 

    return 0;
}