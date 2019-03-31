#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
typedef pair<int,pair<int,int>> ppi;
vector<int> mergeKArrays(vector<vector<int> > arr)
{
    vector<int> output;
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    for(ll i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty())
    {
        ppi current=pq.top();
        pq.pop();
        int i=current.second.first;
        int j=current.second.second;
        output.push_back(current.first);
        if(j+1<arr[i].size())
        {
            pq.push({ arr[i][j + 1], { i, j + 1 } }); 
        }
    }
    return output; 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int> > arr{ { 2, 6, 12 }, 
                              { 1, 9 }, 
                              { 23, 34, 90, 2000 } }; 
  
    vector<int> output = mergeKArrays(arr); 
  
    cout << "Merged array is " << endl; 
    for (auto x : output) 
        cout << x << " "; 
    return 0;
}