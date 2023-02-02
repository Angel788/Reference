//Se usa para detectar cyclos en un grafo no dirigido convexo & en el algoritmo de Krustal.
vector<pair<int,int>>ds;
void init(int n){
    ds.assign(n+1,{-1,0});
}
int find(int x){
    if(-1==ds[x].first) return x;
    return ds[x].first=find(ds[x].first);
}
bool unionDs(int x, int y){
    int px=find(x),py=find(y);
    int &rx=ds[px].second,&ry=ds[py].second;
    if(px==py) return false;
    else{
        if(rx>ry) ds[py].first=px;
        else{
            ds[px].first=py;
            if(rx==ry) ry+=1; 
        }
    }
    return true;
}
