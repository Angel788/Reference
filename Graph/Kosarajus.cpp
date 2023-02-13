//Sirve para encontrar los SCC
struct Kosaraju{
    int s;
    vector<vector<int>> g,gr;
    vector<int> visited,ids,topologic_sort;
    Kosaraju(int n){
        s=n;
        g.assign(n+1,vector<int>());
        gr.assign(n+1,vector<int>());
        visited.assign(n+1,0);
        ids.assign(n+1,0);
    }
    void addEdge(int a,int b){
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    void dfs(int u){
        if(visited[u]!=0) return;
        visited[u]=1;
        for(int node:g[u])dfs(node);
        topologic_sort.push_back(u);
    }
    void dfsr(int u,int id){
        if(visited[u]!=0) return;
        visited[u]=1;
        ids[u]=id;
        for(int node:gr[u])dfsr(node,id);
    }
    void algo(){
        for(int i=1;i<=s;i++) if(visited[i]==0) dfs(i);
        fill(visited.begin(),visited.end(),0);
        reverse(topologic_sort.begin(),topologic_sort.end());
        int id=0;
        for(int i=0;i<topologic_sort.size();i++){
            if(visited[topologic_sort[i]]==0)dfsr(topologic_sort[i],id++);
        } 
    }
    int search(int node){
        return ids[node];
    }
};