#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
void straightminmax(ll a[],ll n,ll max,ll min)
{
    ll max,min,i,count=0;
    max=a[1];
    min=a[1];
    for(i=2;i<=n;i++)
    {
        count++;
        if(a[i]>max)
        {
            max=a[i];
        }
        //count++;
        else if(a[i]<min)
        {
            min=a[i];
        }
        count++;
    }
    cout<<count<<" "<<max<<" "<<min<<" "<<endl;

}
ll count1=0,mid;
void div(ll i,ll j,ll max,ll min,ll a[])
{
    count1++;
    if(i==j)
    {
        max=min=a[i];
        cout<<count1<<" "<<max<<" "<<min<<" "<<endl;
        return;
    }
    else if(i==j-1)
    {
        count1++;
        if(a[i]<a[j])
        {
            max=a[j];min=a[i];
            //count1++;
            cout<<count1<<" "<<max<<" "<<min<<" "<<endl;
            return;
        }
        else
        {
            max=a[i];min=a[j];
            cout<<count1<<" "<<max<<" "<<min<<" "<<endl;
            return;
        }
    }
    else
    {
        mid=(i+j)/2;
        div(i,mid,max,min,a);
        div(mid+1,j,max,min,a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}