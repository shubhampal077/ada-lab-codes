#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
float* preavg2(int arr[],int n)
{
    int count,i;
    float *A=(float *)malloc(sizeof(float)*n);
    float s=0;
    for(i=0,count=0;i<n;i++)
    {
        s+=arr[i];
        A[i]=s/(i+1);
        count++;
    }
    cout<<"value of count is : "<<count<<endl;
    return A;
}
float* preavg1(int arr[],int n)
{
    int a,i,j,count=0;
    float *A=(float *)malloc(sizeof(float)*n);
    for(i=0;i<n;i++)
    {
        for(a=0,j=0;j<=i;j++)
        {
        	a+=arr[j];
        	count++;
        }
        //cout<<a<<" ";
        A[i]=(float)a/(i+1);
    }
    cout<<"count is : "<<count<<endl;
    return A;
}
int main()
{
    int i,j;
    int arr[]={3,4,6,2,7,3,7,5,23,45,67};
    int n=(sizeof(arr)/sizeof(arr[0]));
    float* p=preavg2(arr,n);
    for(i=0;i<n;i++)
        printf("%.2f ",*(p+i));
    return 0;
}