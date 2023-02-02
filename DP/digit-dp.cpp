ll dp[20][20][3];
ll n,k,d;
vector<int>num;
ll bk(int i, int len, int t){
    if(len>k) return 0;
    if(i==n){
        if(len==k) return 1;
        return 0;
    }
    ll &res=dp[i][len][t];   
    if(res!=-1) return res;
    res=0;
    int tope;
    if(t==0) tope=num[i];
    else tope=9;
    for(int j=0;j<=tope;j++){
        int newt=t;
        int newlen=len;
        if(t==0 && j<tope) newt=1;
        if(d==j) newlen++;
        if(newlen<=k)res+=bk(i+1,newlen,newt);
    }
    return res;
}
ll rep(int a){
    num.clear();
    while(a>0){
        num.push_back(a%10);
        a/=10;
    }
    reverse(num.begin(),num.end());
    n=num.size();
    memset(dp,-1,sizeof(dp));
    return bk(0,0,0);
}