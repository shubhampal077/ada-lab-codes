#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int i,j,n,key;
    cout<<"enter n\n";
    cin>>n;
    int arr[n+1];
    cout<<"enter "<<n<<"nos \n";
    for(i=1;i<=n;i++)
        cin>>arr[i];
    for(j=2;j<=n;j++)
    {
        key=arr[j];
        i=j-1;
        while(i>0 && arr[i]>key)
        {
            arr[i+1]=arr[i];
            i--;
        }
        arr[i+1]=key;
    }
    cout<<"output sequence is :\n";
    for(i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    return 0;
}