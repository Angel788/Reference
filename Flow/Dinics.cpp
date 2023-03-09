struct dinics{
    int m,n;
    ll mF=1e18;
    vector<tuple<int,ll,ll>>edge;
    vector<vector<int>>adj;
    vector<int>level,id;
    void init(int _n){
        m=0;
        n=_n;
        level.resize(n+1);
        id.resize(n+1);
        adj.resize(n+1);
    } 
    void addEdge(int u,int v,ll f,bool directed=true){
        edge.push_back({v,f,0});
        adj[u].push_back(m);
        edge.push_back({u,(directed?0:f),0});
        adj[v].push_back(m+1);
        m+=2;
    }
    bool bfs(int s, int t){
        fill(level.begin(),level.end(),-1);
        queue<int>aux;
        aux.push(s);
        level[s]=0;
        while(!aux.empty()){
            int v=aux.front();aux.pop();
            for(auto idx:adj[v]){
                auto &[u,c,f]=edge[idx];
                if(c-f<1 || level[u]!=-1) continue;
                aux.push(u);
                level[u]=level[v]+1;
            }
        }
        return level[t]!=-1?1:0;
    }
    ll dfs(int u,int t, ll f){
        if(u==t || f==0) return f;
        for(auto &cdx=id[u];cdx<adj[u].size();cdx++){
            int idx=adj[u][cdx];
            auto &[v,c,fv]=edge[idx];
            if(level[v]!=level[u]+1 || c-fv<1) continue;
            ll res=dfs(v,t,min(f,c-fv));
            if(!(res)) continue;
            auto &fr=get<2>(edge[idx^1]);
            fv+=res;
            fr-=res;
            return res;
        }
        return 0;
    }
    ll maxFlow(int s,int t){
        ll mf=0;
        while(bfs(s,t)){
            fill(id.begin(),id.end(),0);
            while(ll f=dfs(s,t,mF)) mf+=f;
        }
        return mf;
    }
};
