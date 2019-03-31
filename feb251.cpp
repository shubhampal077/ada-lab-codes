#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    ll amt,temp;
    //cout<<"enter no of denominations\n";
    cin>>n;
    //cout<<"enter denominations\n";
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<ll>());
    //cout<<"enter amount"<<endl;
    
    cin>>amt;
    temp=amt;
    ll i=0;
    while(temp!=0 && i<n)
    {
        if(temp>=arr[i])
        {
            x=temp/arr[i];
            temp=temp%arr[i];
            //i++;
            cout<<"no of "<<arr[i]<<" denominations are : "<<x<<endl;
        }
            i++;
            
    }
    return 0;
}