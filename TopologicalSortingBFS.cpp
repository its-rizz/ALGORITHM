#include<bits/stdc++.h>
using namespace std;

const int N=10e5;
vector <int> adj[N];


int main()
{
    int n,e; cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
    }

    vector <int> indegree(n,0);
    for(int i=0;i<n;i++)
    {
        for(auto &it:adj[i])
            indegree[it]++;
    }

    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int i=q.front(); q.pop();
        cout<<i<<" ";

        for(auto &it:adj[i])
        {
            indegree[it]--;
            if(indegree[it]==0)
                q.push(it);
        }

    }    
    return 0;
}
