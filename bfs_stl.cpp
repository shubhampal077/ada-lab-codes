#include<bits/stdc++.h>
//***************Constraints are always imaginary,I'm real :)**************
using namespace std;
typedef long long int ll;
void dfs(vector<vector<int>> &mat,int start)
{
    static vector<bool> visited(mat.size(),false);
    if(!visited[start])
    {
        cout<<start<<" ";
        visited[start]=true;
        for(int j=1;j<=mat.size();j++)
        {
            if(mat[start][j]==1 && !visited[j])
            {
                //cout<<j<<" ";
               // visited[j]=true;
                dfs(mat,j);
            }
        }
    }

}
void bfs(vector<vector<int>> &mat,int start)//using adjacency matrix
{
    vector<bool> visited(mat.size(),false);
    queue<int> q;
    cout<<start<<" ";
    visited[start]=true;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=mat.size();v++)
        {
            if(mat[u][v]==1 && !visited[v])
            {
                cout<<v<<" ";
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int v=4;
    vector<vector<int>> mat{
        {0,0,0,0,0},
        {0,0,1,0,1},
        {0,1,0,1,1},
        {0,0,1,0,1},
        {0,1,1,1,0}
    };
    int start=1;
    dfs(mat,start);
    return 0;
}