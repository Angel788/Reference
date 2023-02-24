/* f(x)=0 if has square prime factor
f(x)=1 if if is square-free and even
f(x)=-1 if is square-free and odd
properti the sum of function of divisors of x is equl to 0 if x>1*/
vector<int>sieve;
void ms(int n){
    sieve.assign(n+1,-1);
    sieve[1]=1;
    for(int i=2;i<=n;i++)
       for(int j=i*2;j<=n;j+=i)sieve[j]-=sieve[i];
}
