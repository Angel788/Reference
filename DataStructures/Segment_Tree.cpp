int nums[]={1,3,4,5,7};
struct segmentTree{
    int l, r,sum;
    segmentTree *nodeLeft,*nodeRight;
    segmentTree(int a, int b){
        l=a;
        r=b;
        int m=(l+r)/2;
        if(l!=r){
            nodeLeft=new segmentTree(l,m);
            nodeRight=new segmentTree(m+1,r);
            sum=nodeLeft->sum+nodeRight->sum;
        }
        else sum=nums[l];
    }
    int query(int a, int b){
        if(b<l || a>r) return 0;
        if(a<=l && r<=b) return sum;
        return nodeLeft->query(a,b)+nodeRight->query(a,b);
    }
    void update(int pos, int v){
        if(l!=r){
            int m=(l+r)/2;
            if(pos<=m) nodeLeft->update(pos,v);
            else nodeRight->update(pos,v);
            sum=nodeLeft->sum+nodeRight->sum;
        }
        else sum=v;
    }
};
