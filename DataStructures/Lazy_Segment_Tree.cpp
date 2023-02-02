int nums[]={1,3,5,7,9,11};
struct segmentTree{
    int l, r,sum,lazy;
    segmentTree *nodeLeft,*nodeRight;
    segmentTree(int a, int b){
        l=a;
        r=b;
        int m=(l+r)/2;
        lazy=0;
        if(l!=r){
            nodeLeft=new segmentTree(l,m);
            nodeRight=new segmentTree(m+1,r);
            sum=nodeLeft->sum+nodeRight->sum;
        }
        else sum=nums[l];
    }
    int query(int a, int b){
        if(nodeLeft!=nullptr && lazy!=0) nodeLeft->lazy=lazy;
        if(nodeRight!=nullptr && lazy!=0) nodeRight->lazy=lazy;
        sum+=(r-l+1)*lazy;lazy=0;
        if(b<l || a>r) return 0;
        if(a<=l && r<=b) return sum;
        return nodeLeft->query(a,b)+nodeRight->query(a,b);
    }
    int update(int a, int b, int v){
        int increment=0;
        if(b<l || a>r) return 0;
        if(a<=l && r<=b){
            if(nodeLeft!=nullptr) nodeLeft->lazy+=lazy;
            if(nodeRight!=nullptr) nodeRight->lazy+=lazy;
            increment=(r-l+1)*v;
            sum+=increment;
            return increment;
        }
        increment=nodeLeft->update(a,b,v)+nodeRight->update(a,b,v);
        sum+=increment;
        return increment;
    }
};
