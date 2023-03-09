#include <bits/stdc++.h>
#define ll long long 
using namespace std;
struct dinics{
    int m=0,n;
    ll maxFlow=1e18;
    vector<tuple<int,ll,ll>edge;
    vector<vector<int>>adj;
    vector<int>level,id;
    void init(int _n){
        n=_n;
        level.resize(n+1);
        index.resize(n+1);
        adj.resize(n+1);
    } 
    void addEdge(int u,,int v,ll f){
        edge.push_back({u,f,0});
        adj[u].push_back(m)
        edge.push_back({v,f,0});
        adj[u].push_back(m+1);
        m+=2;
    }
    bool bfs(int s, int t){
        fill(level.begin(),level.end(),-1);
        queue<int>aux;
        aux.push(s);
        while(!aux.empty()){
            int v=aux.front();aux.pop();
            for(auto idx:adj[v]){
                auto &[u,c,f]=edge[idx];
                if(c-f<0 || level[idx]!=-1) continue;
                aux.push(u);
                level[u]=level[v]+1;
            } 
        }
        return level[t]!=-1?1:0;
    }
    ll dfs(int u, ll f){
        if(f==0) return 0;
        for(auto &cdx=id[u];cdx<adj[u].size();cdx++){
            int idx=adj[u][cdx];
            auto &[v,c,f]=edge[idx]; 
            if(level[v]!=level[u]+1 || f-c<1) continue;
            ll res;
            if(!(res=dfs(v,min(c-f))) continue;
            auto &fr=get<2>edge[idx^1];
            f+=res;
            fr-=res;
            return res;
        }
        return 0;
    }
    ll maxFlow(int s,int t){
        ll f=0;
        while(bfs(s,t)){
            fill(id.begin(),id.end(),0);
            while(f+=dfs(s,maxFlow));
        }
        return f;
    }
}