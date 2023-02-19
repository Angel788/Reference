#include <bits/stdc++.h>
using namespace std;
typedef struct Node *pitem;
struct Node{
    int x,y;
    pitem l,r;
    Node(int v) x(v),y(rand()),l(nullptr),r(nullptr);
};
vector<int> rank;//1)optiona 2)intialize this array n+1
pair<pitem,pitem> split(pitem root,int value){
    pitem b=root->r;
    if(!root) return {nullptr,nullptr};
    if(root->x==value){
        pitem b=root->r;
        root->r=nullptr;
    }
    else{
        if(root->x>value) return split(root->l,value);
        else return split(root->r,value);
    }
    return {root,b};
}
void leftRotation(pitem x,int value){
    pitem y,a,b,c;
    tie(x,y)=split(x,value);
    tie(y,c)=split(y,y->y);
    a=x->l;b=y->l;
    x->r=c;x->l=y;
    y->l=a;y->r=b;
    swap(x->x,y->x);swap(x->y,y->y);
}
void rightRotation(pitem x,int value){
    pitem y=x->l,a,b,c;
    tie(x,c)=split(x,value);
    tie(y,b)=split(y,y->y);
    a=y->l;
    x->r=y;
    y->l=b;y->r=c;
    x->l=a;
    swap(x->x,y->x);swap(x->y,y->y);
}
void insert(pitem root,int value){
    if(!root){
        root=new Node(value);
        return;
    }
    insert((root->x>value?root->l,root->r),value);
    if(root->l && root->l->y>root->y) leftRotation(root,root->y);
    if(root->r && root->r->y>root->y) leftRotation(root,root->y);
}
//optional
int dfs(pitem root){
    if(root->l) rank[root->x]+=dfs(root->l);
    if(root->r) rank[root->x]+=dfs(root->r);
    return rank[root->x]+=1;
}


