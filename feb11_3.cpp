#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll arr[]={4,-1,7,-7,8,9,-3};
    ll size=7,j=-1;
    for(int i=0;i<size;i++)
    {
        if(arr[i]<0)
        {
            j++;
            swap(arr[j],arr[i]);
        }
    }
    for(ll i=0;i<size;i++)
        cout<<arr[i]<<" ";
    return 0;
}