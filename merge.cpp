#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
void merge(int A[],int start,int mid,int end)
{
    int p=start,q=mid+1,i;
    int arr[end-start+1],k=0;
    for(i=start;i<=end;i++)
    {
        if(p>mid)
            arr[k++]=A[q++];
        else if(q>end)
            arr[k++]=A[p++];//merging two sub-lists into an auxiliary array
        else if(A[p]<A[q])
            arr[k++]=A[p++];
        else 
            arr[k++]=A[q++];
    }
    for(i=0;i<k;i++)
        A[start++]=arr[i];//copying back to original array
}
void merge_sort(int A[],int start,int end)
{
    if(start<end)
    {
        int mid=(start+end)/2;
        cout<<"hello i am in one   "<<start<<" "<<mid<<" "<<end<<endl;
        merge_sort(A,start,mid);
        cout<<"hello i am in two   "<<start<<" "<<mid<<" "<<end<<endl;
        merge_sort(A,mid+1,end);
        cout<<"hello i am in three  "<<start<<" "<<mid<<" "<<end<<endl;
        merge(A,start,mid,end);
        cout<<"hello i am in four  "<<start<<" "<<mid<<" "<<end<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int A[]={9,7,8,3,2,1};
    int i;
    merge_sort(A,0,5);
    for(i=0;i<6;i++)
        cout<<A[i]<<" ";
    return 0;
}