const int MAX=50
ll prefix[MAX+4][MAX+4];
// x1-> left x2->right y1-> up  y2 ->down x1<=x2 && y1<=y2
ll query(int x1, int x2,int y1,int y2){
    return prefix[y2][x2]-prefix[y1-1][x2]-prefix[y2][x1-1]+prefix[y1-1][x1-1];
}
//Inizialisate prefix[i][j] with original values of the grid
void prefixSum(){
        for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) prefix[i][j]+=prefix[i][j-1]+prefix[i-1][j]-prefix[i-1][j-1];
    }
}
