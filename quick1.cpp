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
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi= partition(arr,low,high);
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
    int index;
    int arr[]={27,82,31,5,98,23,45};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"enter the index in which you want to set pivot\n ";
    cin>>index;
    swap(arr[0],arr[index]);
    quicksort(arr, 0, n - 1); 
    cout<<"Sorted array: \n"; 
    printArray(arr, n); 

    return 0;
}