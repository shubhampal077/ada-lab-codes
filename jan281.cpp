#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,sum,p,i,j;
    cin>>n>>p;
    ll arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    i=0;j=n-1;
    while(i<=j)
    {
        sum=arr[i]+arr[j];
        if(sum>p)
            j--;
        else if(sum<p)
            i++;
        else if(sum==p)
        {
            cout<<"indices are : \n"<<i<<" "<<j;
            break;
        }
    }
    return 0;
}