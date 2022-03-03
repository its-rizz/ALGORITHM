#include<bits/stdc++.h>
using namespace std;

const int N=10e5;
vector <int> adj[N];


void dfs(vector <int> &ordering,vector <bool> &visited,int node)
{
    visited[node]=true;
    for(auto &it:adj[node])
    {
        if(!visited[it])
            dfs(ordering,visited,it);
    }
    ordering.push_back(node);
}

int main()
{
    int n,e; cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }

    vector<bool> visited(n,false);
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            dfs(result,visited,i);
    }

    reverse(result.begin(),result.end());

    for(auto &it:result)
        cout<<it<<" ";
    cout<<endl;
    
    return 0;
}
