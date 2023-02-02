// Este algoritmo sirve para buscar MST de un grafo convexo no dirigido
vector<tuple<int,int,int>>edges;
int n;m;
//Insertar Disjoin set
int krustal(){
    sort(edges.begin(),edges.end());
    int res=0;
    for(int i=0;i<m;i++){
        int c,a,b;
        tie(c,a,b)=edges[i];
        if(unionDs(a,b)==false) continue;
        else res+=c;
    }
    return res;
}
