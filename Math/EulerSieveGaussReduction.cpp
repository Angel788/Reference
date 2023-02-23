// sum(pi(n)) of the divisors of n is equal to n
vector<int>sieve;
void eulerSieve(int n){
    sieve.clear();
    sieve.push_back(0);
    sieve.push_back(1);
    for(int i=2;i<=n;i++){
        sieve.push_back(i-1);
    }
    for(int i=2;i<=n;i++){
            for(int j=i*2;j<=n;j+=i)sieve[j]-=sieve[i];    
    }
}
