#include<bits/stdc++.h>

//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
#define INF 0x3f3f3f3f 
typedef long long int ll;
typedef pair<int,int> ipair;
void addEdge(vector<ipair> adj[],int u,int v,int wt)
{
    adj[u].push_back(make_pair(v,wt));
    adj[v].push_back(make_pair(u,wt));
}
void shortestPath(vector<ipair> adj[],int V,int src)
{
    priority_queue<ipair,vector<ipair>,greater<ipair>> pq;
    vector<int> dis(V,INF);
    pq.push(make_pair(0,src));
    dis[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        //vector<ipair>::iterator it=adj[u].begin();
        for(auto x:adj[u])
        {
            int v = x.first;
            int weight=x.second;
            if(dis[v]>dis[u]+weight)
            {
                dis[v]=dis[u]+weight;
                pq.push(make_pair(dis[v],v));
            }
        }
    }
    cout<<"Vertex Distance from Source\n"<<endl; 
    for (int i = 0; i < V; ++i) 
        cout<<i<<" "<<dis[i]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int V=9;
    vector<ipair> adj[V];
    addEdge(adj, 0, 1, 4); 
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
  
    shortestPath(adj, V, 0);
    return 0;
}