#include<bits/stdc++.h>
using namespace std;
class graph 
{
    private:
        int vertices,edges;
        vector<int> adj[21];
        map<int,bool>vis;
        int countVertices=0,countEdges=0;
    public:
        void dfs(int s)
        {
            vis[s]=true;
            cout<<s<<" ";
            countVertices++;
            for(auto v:adj[s])
            {
                if(!vis[v])
                dfs(v);
            }
        }
        void bfs(int s)
        {
            for(int i=0;i<vis.size();i++)
            {
                vis[i]=false;
            }
            vis[s]=true;
            list<int>queue;
            queue.push_back(s);
            while(!queue.empty())
            {
                s=queue.front();
                cout<<s<<" ";
                queue.pop_front();
                for(auto v:adj[s])
                {
                    if(!vis[v])
                    {
                       vis[v]=true;
                       queue.push_back(v);     
                    }
                }
            }
        }
        bool isCyclic(int v,int parent)
        {
            vis[v]=true;
            for(auto i=adj[v].begin();i!=adj[v].end();i++)
            {
                if(!vis[*i])
                {
                    if(isCyclic(*i,v))
                    return true;
                }
                else if(*i!=parent)
                return true;
            }
            return false;
        }
        bool cylic()
        {
            for(int i=0;i<vis.size();i++)
            {
                vis[i]=false;
            }
            
            for(int u=0;u<vertices;u++)
            {
                if(!vis[u])
                {
                    if(isCyclic(u,-1))
                    return true;
                }
            }
            return false;
        }
        bool biPartite(int v,vector<int>&color)
        {
            for(int u:adj[v])
            {
                if(vis[u]==false)
                {
                    vis[u]=true;
                    color[u]=!color[v];
                    if(!biPartite(u,color))
                        return false;
                }
                else if(color[u]==color[v])
                    return false;
            }
            return true;
        }
        void create(int n,int m)
        {
            vertices=n; edges=m;
            int u,v;
            cout<<"Enter the edges:";
            for(int i=0;i<edges;i++)
            {
                cin>>u>>v;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
            int x; 
            cout<<"Enter from which vertex you want to perform DFS&BFS:";
            cin>>x;
            cout<<"DFS from vertex "<<x<<" is:";
            dfs(x); cout<<endl;
            cout<<"BFS from vertex "<<x<<" is:";
            bfs(x); cout<<endl;
            if(countVertices<vertices)
            {
                cout<<"The given graph is not connected"<<endl;
            }
            else 
            {
                cout<<"The given graph is connected"<<endl;
            }

            if(cylic())
            {
                cout<<"The graph is cyclic"<<endl;
            }
            else 
            {
                cout<<"The graph is acyclic"<<endl;
            }
            vector<int>color(vertices+1);
            for(int i=0;i<vis.size();i++)
            {
                vis[i]=false;
            }
            vis[x]=true; color[x]=0;
            if(biPartite(x,color))
            {
                cout<<"Graph is bipartite"<<endl;
            }
            else 
            {
                cout<<"Graph is not biPartite"<<endl;
            }
        }

};
int main()
{
    int n,m;
    cout<<"Enter the number of verices and edges:";
    cin>>n>>m;
    graph g;
    g.create(n,m);
    return 0;
}