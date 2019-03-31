#include<bits/stdc++.h>
using namespace std;
int a[100];
int link[100]={0};

int merge(int q,int r)
{
    int i=q;
    int j=r;
    int k=0;
   
    while(i&&j)
    {
        if(a[i]<=a[j])
        {
            link[k]=i;
            k=i;
            i=link[i];
        }
        else
        {
            link[k]=j;
            k=j;
            j=link[j];
        }
    }
    if(!i)
    link[k]=j;
   
    else if(!j)
    link[k]=i;
   
    return (link[0]);
   
}

int mergesort(int low,int high)
{
    if(low<high)
    {
       int  mid=(low+high)/2;
        int q=mergesort(low,mid);
        int r=mergesort(mid+1,high);
        return merge(q,r);
    }
 else
   return low;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    int x=mergesort(1,n);
    cout<<a[x]<<" ";
    while(link[x]!=0)
    {
        cout<<a[link[x]]<<" ";
        x=link[x];
    }
   
 
 
   
}
