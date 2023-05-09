#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+300;
int S[MAX];
int F[MAX];
int FT[MAX];
vector<int>T[MAX];
//Inicalizar en 0 para 0 indexado y 1 par 1 indexado
int timer;
int n;
void dfs(int node,int par){
    S[node]=timer;
    FT[timer]=node;
    timer++;
    for(auto i:T[node])
       if(i!=par) dfs(i,node);
    F[node]=timer;
    FT[timer]=node;
    timer++;   
}

