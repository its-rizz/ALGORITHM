#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector <pair<int,int>> adj[N];//Using the adjacency list representation for the graph


int primsAlgorithm(int n)
{
    //Creating the priority queue on the basis of the edge weight

    priority_queue<pair<int,int>> q;
    //({weight,edge})


    q.push({0,0});
    int ans=0;
    vector <bool> visited(n,false);

    while(!q.empty())
    {
        auto best=q.top(); q.pop();

        auto to=best.second;
        int weight=best.first;

        if(visited[to])
            continue;

        ans+=((-1)*weight);//We are storing the negative weight and hence multiply the weight by -1 to make the weight value positive
        visited[to]=true;

        for(auto &it:adj[to])
        {
            if(!visited[it.first])
                q.push({(-1)*it.second,it.first});//Adding the negative weight such that the priority queue act like the min heap
        }

    }

    return ans;

}

int main()
{
    int n,e; cin>>n>>e; //Take the number of edges and the number of vertices on the graph

    while(e--)
    {
        int a,b,weight; cin>>a>>b>>weight;//adding the edge to the graph
        adj[a].push_back({b,weight});
        adj[b].push_back({a,weight});
    }

    
    cout<<primsAlgorithm(n)<<endl;

}
