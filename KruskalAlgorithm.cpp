#include<bits/stdc++.h>
using namespace std;


const int N=1e5;
vector <vector<int>> adj;

class DSU{
    int n;
    int *parent;
    int *rank;
public:

    DSU(int n)
    {
        this->n;
        parent = new int[n];
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        rank=new int[n];
        for(int i=0;i<n;i++)
            rank[i]=i;
    }

    int find(int x) //This function the parent of the particular node passed
    {
        if(parent[x]==x) //IF the value of the parent array is equal to itself then it means the current node is the parent of itself
            return x;

        return parent[x]=find(parent[x]); //Else if the parent of the node x
        
    }


    int unite(int a,int b)//This function will union of the nodes a and b
    {
        int s1=find(a);
        int s2=find(b);

        if(s1!=s2)//Union only if the parent of the both nodes are different
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=parent[s1];
                rank[s1]+=rank[s2];
            }
        }
    }
};


int Kruskal(int n)
{
    
    int result=0;
    sort(adj.begin(),adj.begin()+n);

    DSU ds(n);
    for(int i=0;i<n;i++)
    {
        int a=adj[i][1];
        int b=adj[i][2];

        if(ds.find(a)!=ds.find(b))
        {
            ds.unite(a,b);
            result+=adj[i][0];
        }

    }
    
    return result;
}


int main()
{
    int n,e; cin>>n>>e; //Take the number of edges and the number of vertices from the user

    while(e--)
    {
        int a,b,weight; cin>>a>>b>>weight;
        adj.push_back({weight,a,b});
    }

    cout<<Kruskal(n)<<endl;

}
