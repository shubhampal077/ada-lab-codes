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
int partition_r(int arr[], int low, int high) 
{ 
    //srand(time(NULL)); 
    int random = low + (rand() % (high - low)); 
    swap(arr[random], arr[high]); 
    //cout<<random<<endl;
    return partition(arr, low, high); 
}
int kthSmallest(int arr[], int l, int r, int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    {
        int pos = partition_r(arr, l, r); 
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k); 
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
}


int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    cout << "K'th smallest element is " << kthSmallest(arr, 0, n-1, k); 
    return 0;
}