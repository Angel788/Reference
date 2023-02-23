//this is a sieve for a euler funciton that given the number of coprime numbers of x but in a range
vector<int>sieve;
void eulerSieve(int n){
    sieve.clear();
    sieve.push_back(0);
    for(int i=1;i<=n;i++){
        sieve.push_back(i);
    }
    for(int i=2;i<=n;i++){
        if(sieve[i]==i)
            for(int j=i;j<=n;j+=i)sieve[j]-=(sieve[j]/i);
    }
}
