//For get the k-th atecesor of a node in a tree
vector<int> *T;
vector<vector<int>>up;
vector<int>deep;
int lg;
void init(int n){
    lg=ceil(log2(n));
    T=new vector<int>[n+1];
    up.assign(n+1,vector<int>(lg+1,1));
    deep.assign(n+1,0);
}
void dfs(int node){
    for(auto ch:T[node]){
        deep[ch]=deep[node]+1;
        up[ch][0]=node;
        for(int i=1;i<lg;i++){
            up[ch][i]=up[up[ch][i-1]][i-1];
        }
        dfs(ch);
    }
}
int getkthAtecesor(int node, int k){
    int res=node;
    for(int i=lg-1;i>=0;i--){
        if(k & (1<<i)) res=up[res][i];
    }
    return res;
}