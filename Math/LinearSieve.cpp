#include <bits/stdc++.h>
using namespace std;
bool is_compositive[10000000+1];
vector<int>primes;
void sieve(int n){
    primes.clear();
   fill(is_compositive,is_compositive+n,false);
   for(int i=2;i<=n;i++){
    if(!is_compositive[i]) primes.push_back(i);
    for(int j=0;j<primes.size() && primes[j]*i<=n;j++){
        is_compositive[i*primes[j]]=true;
        if(!(i%primes[j])) break;
    }
   } 
}
int main(){
    int n;cin>>n;
    sieve(n);
    cout<<primes.size()<<endl;
    for(int i=0;i<primes.size();i++){
        cout<<primes[i]<<endl;
    }
}